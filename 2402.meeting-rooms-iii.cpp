/*
 * @lc app=leetcode id=2402 lang=cpp
 *
 * [2402] Meeting Rooms III
 */

// @lc code=start

#define ll long long

class Solution {
public:
// This function calculates the maximum number of meetings that can be accommodated in a given number of rooms.
int mostBooked(int n, vector<vector<int>>& meetings) {
    // Priority queue to store the available rooms, sorted in ascending order of room numbers
    priority_queue<ll, vector<ll>, greater<ll>> availableRooms;
    // Priority queue to store the busy rooms, sorted in ascending order of the end time of the meetings
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> busyRooms;
    // Array to keep track of the number of meetings assigned to each room
    vector<ll> roomCount(n, 0);

    // Sort the meetings based on their start times
    sort(meetings.begin(), meetings.end());

    // Initialize the available rooms in the priority queue
    for (int i = 0; i < n; i++) {
        availableRooms.push(i);
    }

    // Iterate through each meeting
    for (auto meet : meetings) {
        ll start = meet[0], end = meet[1];

        // Check if there are any available rooms or if any room becomes available before the start time of the current meeting
        while (!busyRooms.empty() && start >= busyRooms.top().first) {
            // Add the room back to the available rooms queue
            availableRooms.push(busyRooms.top().second);
            busyRooms.pop();
        }

        if (availableRooms.size()) {
            // Assign the meeting to an available room
            ll room = availableRooms.top();
            availableRooms.pop();
            busyRooms.push({end, room}); // Mark the room as busy with the end time of the meeting
            roomCount[room]++; // Increment the meeting count for the assigned room
        } else {
            // If no room is available, find the next meeting that ends and extend its end time
            pair<ll, ll> nextMeet = busyRooms.top();
            busyRooms.pop();
            busyRooms.push({nextMeet.first + (end - start), nextMeet.second}); // Extend the end time of the meeting
            roomCount[nextMeet.second]++; // Increment the meeting count for the extended meeting's room
        }
    }

    // Return the room with the maximum number of meetings assigned to it
    return max_element(roomCount.begin(), roomCount.end()) - roomCount.begin();
}
};
// @lc code=end

