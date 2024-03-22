/*
*   Author: kamerado
*   Date: March 17, 2024
*
*   Clock.cpp
*/

#include <iostream> // using iostream to output to terminal, and get input from terminal.
#include <iomanip> // Using iomanip to format clock output and main menu output.
#include <limits> // For numeric limits.
using namespace std;

// This is to keep everything formatted nicely. Clears screen on windows or linux machines, keeping the code functional for both systems.
void clrscr() {

    cout << "\033[2J\033[1;1H";

}

// Converts minutes or seconds into string values.
string MinSecToString(int num) {
    string numString; 

    if (num < 10) { // Add 0 to single digit values. conv to string.
        numString = "0" + to_string(num);
    } else { // Conv to string.
        numString = to_string(num);
    }

    return numString;
}

// Converts 12-hour values to string.
string HoursToString(int hours) {
    string hoursString;

    if (hours < 10) { // Add 0 to single digit values. conv to string.
        hoursString = "0" + to_string(hours);
    } else { // Conv to string.
        hoursString = to_string(hours);
    }

    return hoursString;
}

// Converts 12 hour time to 24 hour time, returns as string value.
string Hours24ToString(int hours, string AmPm) {
    string hours24String;

    
    if ((AmPm == "PM") && (hours != 12)) { // Add 12 to acheive 24-hour, hour value.
        hours24String = to_string(hours + 12);
    } else if ((AmPm == "PM") && (hours == 12)) { // Conv to string if not midnight.
        hours24String = to_string(hours);
    } else if ((AmPm == "AM") && (hours == 12)) { // Conv to string as 00 if at midnight.
        hours24String = "00";
    } else if (hours < 10) { // Add 0 to single digit values. conv to string.
        hours24String = "0" + to_string(hours);
    } else { // Conv to string.
        hours24String = to_string(hours);
    }

    return hours24String;
}

// Print menu.
void PrintMenu() {

    cout << "***************************" << endl;
    cout << "* 1 - Add One Hour        *" << endl;
    cout << "* 2 - Add One Minute      *" << endl;
    cout << "* 3 - Add One Second      *" << endl;
    cout << "* 4 - Exit Program        *" << endl;
    cout << "***************************" << endl << endl;
}

// Print clocks using setw() to pad, formatting the clocks correctly.
void PrintClocks(int hours, int minutes, int seconds, string AmPm) { // using paramaters to print correct time, calling To24Hour() to convert the 12 hour time to 24 hour time.
    // declare local variables.
    string hoursString;
    string hours24String;
    string minutesString;
    string secondsString;

    // convert all int to string, this is beacuse formatting ints with printf inside of cout statements causes unexpected behavior. Done to acheive 01, 02, etc and not 1, 2, etc. 
    hoursString = HoursToString(hours);
    hours24String = Hours24ToString(hours, AmPm);
    minutesString = MinSecToString(minutes);
    secondsString = MinSecToString(seconds);

    cout << "***************************    ***************************" << endl;

    cout << "*" << setw(19) << "12-hour clock" << setw(7) << "*";
    cout << "    ";
    cout << "*" << setw(19) << "24-hour clock" << setw(7) << "*" << endl;

    cout << "*" << setw(9) << hoursString << ":" << minutesString << ":" << secondsString << " " << AmPm << setw(8) << "*";
    cout << "    ";
    cout << "*" << setw(11) << hours24String << ":" << minutesString << ":" << secondsString << setw(9) << "*" << endl;

    cout << "***************************    ***************************" << endl << endl;

}

// Get initial time from user.
void GetInitialTime(int& hours, int& minutes, int& seconds, string& AmPm) {
    int AmPmInput = -1;

    clrscr();
    while ((hours < 1) || (hours > 12)) { // Make sure values are proper hour values.

        cout << "Please enter hours." << endl;
        cin >> hours;

        if (cin.fail()) { // Check if the input failed
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            clrscr();
            cout << "Please enter a number between 1-12. (integer values only)" << endl;
            continue; // Continue the loop
        }

        if ((hours < 1) || (hours > 12)) { // If values are not within 1-12, display message for user and loop again.
            clrscr();
            cout << "Please enter a number between 1-12." << endl;
        }
    }

    clrscr();
    while ((minutes < 0) || (minutes > 59)) { // Make sure values are proper minute values.

        cout << "Please enter minutes." << endl;
        cin >> minutes;

        if (cin.fail()) { // Check if the input failed
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            clrscr();
            cout << "Please enter a number between 0-59. (integer values only)" << endl;
            continue; // Continue the loop
        }

        if ((minutes < 0) || (minutes > 59)) { // If values are not within 0-59, display message for user and loop again.
            clrscr();
            cout << "Please enter a number between 0-59." << endl;
        }
    }

    clrscr();
    while ((seconds < 0) || (seconds > 59)) { // Make sure valus are proper second values.
        
        cout << "Please enter seconds." << endl;
        cin >> seconds;

        if (cin.fail()) { // Check if the input failed
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            clrscr();
            cout << "Please enter a number between 0-59. (integer values only)" << endl;
            continue; // Continue the loop
        }

        if ((seconds < 0) || (seconds > 59)) { // If values are not within 0-59, display message for user and loop again.
            clrscr();
            cout << "Please enter a number between 0-59." << endl;
        }
    }

    clrscr();
    while ((AmPmInput < 1) || (AmPmInput > 2)) {
   
        cout << "Please select AM or PM." << endl;
        cout << "1) AM" << endl << "2) PM" << endl;
        cin >> AmPmInput;

        if (cin.fail()) { // Check if the input failed
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            clrscr();
            cout << "Please choose between 1 or 2. (integer values only)" << endl;
            continue; // Continue the loop
        }

        if ((AmPmInput < 1) || (AmPmInput > 2)) { // If values are not within 1-2, display message for user and loop again.
            clrscr();
            cout << "Please choose between 1 or 2." << endl;
        } else if (AmPmInput == 1) { // Chose 1.
            AmPm = "AM";
        } else if (AmPmInput == 2) { // Chose 2.
            AmPm = "PM";
        }
    }
}

void AddHour(int& hours, string& AmPm) {

    if ((hours == 12)) { // Ensure hours do not go above 12
        hours = 1;
    } else if ((hours == 11) && (AmPm == "AM")) { // Change from AM to PM.
        hours += 1;
        AmPm = "PM";
    } else if ((hours == 11) && (AmPm == "PM")) { // Change from PM to AM.
        hours += 1;
        AmPm = "AM";  
    } else { // Add hour otherwise.
        hours += 1;
    }

}

// Add minute.
void AddMinute(int& hours, int& minutes, string& AmPm) {

    if (minutes == 59) { // Make sure values don't go over 59.
        minutes = 0; // reset to 0.
        AddHour(hours, AmPm); // Add hour since 60 minutes has passed.
    } else {
        minutes += 1; // Add minute.
    }

}

// Add second.
void AddSecond(int& hours, int& minutes, int& seconds, string& AmPm) {

    if (seconds == 59) { // Make sure values don't go over 59.
        seconds = 0; // reset to 0.
        AddMinute(hours, minutes, AmPm); // Add minute since 60 seconds have passed.
    } else {
        seconds += 1; // Add second.
    }

}

// Entree point.
int main() {

    // Variables used to store time values.
    int input = -1;
    int hours = -1;
    int minutes = -1;
    int seconds = -1;
    string AmPm = "\0";

    // Get initial time from user.
    GetInitialTime(hours, minutes, seconds, AmPm);
    
    // Main loop.
    clrscr();
    while (input != 4) {
        
        PrintClocks(hours, minutes, seconds, AmPm); // Print clocks.

        PrintMenu(); // Print menu.

        cin >> input; // Get user input. I could have put this into a function, however it ruined the formatting of the outputs.

        if (cin.fail()) { // Check if the input failed
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            clrscr();
            cout << "Please enter numeric values only. (1-4)" << endl; // Error message if user enters a non-numeric value.
            continue; // Continue the loop
        }

        // Using switch for decision branching.
        switch (input) {

        case 1: // Add hour.
            AddHour(hours, AmPm);
            clrscr();
            break;

        case 2: // Add minute.
            AddMinute(hours, minutes, AmPm);
            clrscr();
            break;
        
        case 3: // Add second.
            AddSecond(hours, minutes, seconds, AmPm);
            clrscr();
            break;

        case 4: // Do nothing, program will terminate.
            break;

        default: // Display error message if values aren't between 1-4.
            clrscr();
            cout << "Please enter a correct input. (1-4)" << endl;
            break;
        }
    }
}