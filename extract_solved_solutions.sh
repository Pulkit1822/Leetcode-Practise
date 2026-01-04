#!/bin/bash

# Script to extract all solved LeetCode solutions
# Author: GitHub Copilot
# Date: May 17, 2025

# Create or clear the output file
OUTPUT_FILE="solved_problems.md"
echo "# My Solved LeetCode Problems" > $OUTPUT_FILE
echo "" >> $OUTPUT_FILE
echo "This document contains all of my successfully solved LeetCode problems." >> $OUTPUT_FILE
echo "" >> $OUTPUT_FILE
echo "## Table of Contents" >> $OUTPUT_FILE
echo "" >> $OUTPUT_FILE

# Find all solution files
SOLUTION_FILES=$(find . -name "*.cpp" -o -name "*.java" -o -name "*.c++" -o -name "*.cs" | sort)

# Counter for problems
count=0

# Loop through each file and extract information
for file in $SOLUTION_FILES; do
    # Extract the problem number and title from the filename
    filename=$(basename "$file")
    problem_info=$(echo "$filename" | sed -E 's/^([0-9]+)\.(.+)\.[a-z+]+$/\1. \2/')
    problem_number=$(echo "$problem_info" | cut -d'.' -f1)
    problem_name=$(echo "$problem_info" | cut -d'.' -f2- | tr '-' ' ' | sed -e 's/\b\(.\)/\u\1/g')
    
    # Get the language from the file extension
    extension="${filename##*.}"
    if [ "$extension" = "cpp" ] || [ "$extension" = "c++" ]; then
        language="C++"
    elif [ "$extension" = "java" ]; then
        language="Java"
    elif [ "$extension" = "cs" ]; then
        language="C#"
    else
        language="Unknown"
    fi
    
    # Check if the file has actual solution code (not empty)
    if [ -s "$file" ]; then
        # Read the first few lines to check if it's a complete solution
        solution_code=$(cat "$file" | grep -E 'class Solution|function' -A 10)
        if [ ! -z "$solution_code" ]; then
            count=$((count+1))
            
            # Add to table of contents
            echo "- [${problem_number}. ${problem_name}](#${problem_number}-${problem_name// /-})" >> $OUTPUT_FILE
            
            # Store for detailed section
            detailed_sections+="### ${problem_number}. ${problem_name}\n\n"
            detailed_sections+="**Language:** ${language}\n\n"
            detailed_sections+="**File:** [\`${filename}\`](${file})\n\n"
            detailed_sections+="<details>\n<summary>View Solution</summary>\n\n\`\`\`${extension}\n$(cat "$file")\n\`\`\`\n\n</details>\n\n"
        fi
    fi
done

# Add summary count
echo "" >> $OUTPUT_FILE
echo "## Summary" >> $OUTPUT_FILE
echo "" >> $OUTPUT_FILE
echo "Total solved problems: **${count}**" >> $OUTPUT_FILE
echo "" >> $OUTPUT_FILE

# Add detailed sections
echo "## Solutions" >> $OUTPUT_FILE
echo "" >> $OUTPUT_FILE
echo -e "${detailed_sections}" >> $OUTPUT_FILE

echo "Extraction complete. Found ${count} solved problems."
echo "Results saved to ${OUTPUT_FILE}"
