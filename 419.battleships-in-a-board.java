/*
 * @lc app=leetcode id=419 lang=java
 *
 * [419] Battleships in a Board
 */

// @lc code=start
class Solution {
    public int countBattleships(char[][] board) {
        int count = 0;
        
        // traverse from left to right, top to bottom and look at each cell
        for(int row = 0; row < board.length; row++) {
            for(int col = 0; col < board[row].length; col++) {
                // only process cells that contains 'X' - a battleship
                if(board[row][col] == 'X') {
                    count += removeShip(board, row, col);
                }
            }
        }
        return count;
    }
    

    private int removeShip(char[][] board, int row, int col) {

        int maxR = board.length;
        int maxC = board[0].length;

        if(row < maxR && col < maxC && row >= 0 && col >= 0) {

            if(board[row][col] == 'X') {
			    System.out.print("[" + row + ", " + col + "] "); 
                board[row][col] = '.'; 
                
                // check adjacent cells
                removeShip(board, row, col - 1);   
                removeShip(board, row, col + 1);                   
                removeShip(board, row + 1, col);    
                removeShip(board, row - 1, col);   
				
				System.out.println(); 
                return 1;
            }
        }        
        return 0;        
    }
}
// @lc code=end

