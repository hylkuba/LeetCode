#include <vector>
#include <algorithm>
#include <iostream>

/**
 * @brief You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a triple booking.

A triple booking happens when three events have some non-empty intersection (i.e., some moment is common to all the three events.).

The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), the range of real numbers x such that start <= x < end.

Implement the MyCalendarTwo class:

MyCalendarTwo() Initializes the calendar object.
boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a triple booking. Otherwise, return false and do not add the event to the calendar.
 

Example 1:

Input
["MyCalendarTwo", "book", "book", "book", "book", "book", "book"]
[[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
Output
[null, true, true, true, false, true, true]

Explanation
MyCalendarTwo myCalendarTwo = new MyCalendarTwo();
myCalendarTwo.book(10, 20); // return True, The event can be booked. 
myCalendarTwo.book(50, 60); // return True, The event can be booked. 
myCalendarTwo.book(10, 40); // return True, The event can be double booked. 
myCalendarTwo.book(5, 15);  // return False, The event cannot be booked, because it would result in a triple booking.
myCalendarTwo.book(5, 10); // return True, The event can be booked, as it does not use time 10 which is already double booked.
myCalendarTwo.book(25, 55); // return True, The event can be booked, as the time in [25, 40) will be double booked with the third event, the time [40, 50) will be single booked, and the time [50, 55) will be double booked with the second event.
 

Constraints:

0 <= start < end <= 109
At most 1000 calls will be made to book.
 * 
 */

class MyCalendarTwo {
    struct SEvent {
        int start;
        int end;

        SEvent(int s, int e) : start(s), end(e) {}

        bool operator<(const SEvent& other) const {
            return start < other.start;
        }
    };

    std::vector<SEvent> singleBooked;
    std::vector<SEvent> doubleBooked;
public:
    MyCalendarTwo() {}

    bool book(int start, int end) {
        // Check if this new event will cause a triple booking
        for (const auto& event : doubleBooked) {
            if (std::max(start, event.start) < std::min(end, event.end)) {
                return false;
            }
        }

        // Now check if it overlaps with singleBooked and create doubleBooked events
        for (const auto& event : singleBooked) {
            if (std::max(start, event.start) < std::min(end, event.end)) {
                int overlapStart = std::max(start, event.start);
                int overlapEnd = std::min(end, event.end);
                doubleBooked.push_back(SEvent(overlapStart, overlapEnd));
            }
        }

        // If no triple booking, insert the new event into singleBooked
        singleBooked.push_back(SEvent(start, end));
        std::sort(singleBooked.begin(), singleBooked.end());

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */

int main(void) {
    MyCalendarTwo* myCalendarTwo = new MyCalendarTwo();
    std::cout << myCalendarTwo->book(10, 20) << std::endl; // return True, The event can be booked. 
    std::cout << myCalendarTwo->book(50, 60) << std::endl; // return True, The event can be booked. 
    std::cout << myCalendarTwo->book(10, 40) << std::endl; // return True, The event can be double booked. 
    std::cout << myCalendarTwo->book(5, 15) << std::endl;  // return False, The event cannot be booked, because it would result in a triple booking.
    std::cout << myCalendarTwo->book(5, 10) << std::endl; // return True, The event can be booked, as it does not use time 10 which is already double booked.
    std::cout << myCalendarTwo->book(25, 55) << std::endl; // return True, The event can be booked, as the time in [25, 40) will be double booked with the third event, the time [40, 50) will be single booked, and the time [50, 55) will be double booked with the second event.
    return 0;
}