#include <iostream>    // Include the library for input and output
#include <vector>     // Include the library for using vectors (dynamic arrays)
#include <string>     // Include the library for using string objects

using namespace std;  // Use the standard namespace to simplify code

// Class definition for the Crossword puzzle
class Crossword {
private:
    vector<vector<char>> grid; // 2D vector to represent the crossword grid
    int size;                  // Variable to store the size of the grid

public:
    // Constructor to initialize the crossword grid with a given size
    Crossword(int n) : size(n) {
        // Resize the grid to size x size and fill with '.' (empty spaces)
        grid.resize(size, vector<char>(size, '.'));
    }

    // Function to display the current state of the grid
    void display() {
        for (const auto& row : grid) {         // Iterate over each row in the grid
            for (char cell : row) {             // Iterate over each cell in the row
                cout << cell << ' ';            // Print the cell followed by a space
            }
            cout << endl;                        // Print a newline after each row
        }
    }

    // Function to add a word to the grid
    bool addWord(const string& word, int row, int col, bool horizontal) {
        // Check if the word should be added horizontally
        if (horizontal) {
            // Check if the word fits within the grid boundaries
            if (col + word.size() > size) return false; 
            
            // Check for conflicts with existing letters in the grid
            for (int i = 0; i < word.size(); ++i) {
                // If there's a conflict, return false
                if (grid[row][col + i] != '.' && grid[row][col + i] != word[i]) {
                    return false; 
                }
            }
            // Place the word in the grid if no conflicts
            for (int i = 0; i < word.size(); ++i) {
                grid[row][col + i] = word[i]; // Insert each letter of the word
            }
        } else { // If the word is to be added vertically
            // Check if the word fits within the grid boundaries
            if (row + word.size() > size) return false; 
            
            // Check for conflicts with existing letters in the grid
            for (int i = 0; i < word.size(); ++i) {
                // If there's a conflict, return false
                if (grid[row + i][col] != '.' && grid[row + i][col] != word[i]) {
                    return false; 
                }
            }
            // Place the word in the grid if no conflicts
            for (int i = 0; i < word.size(); ++i) {
                grid[row + i][col] = word[i]; // Insert each letter of the word
            }
        }
        return true; // Return true if the word was added successfully
    }
};

// Main function
int main() {
    int gridSize; // Variable to store the size of the grid
    cout << "Enter the size of the crossword grid: "; // Prompt user for grid size
    cin >> gridSize; // Read user input

    // Create a Crossword object with the specified size
    Crossword crossword(gridSize);
    
    crossword.display(); // Display the initial empty grid

    string word; // Variable to store the user's word
    int row, col; // Variables to store the starting position (row and column)
    char direction; // Variable to store the direction of the word

    // Loop to continuously allow user input
    while (true) {
        cout << "Enter a word to add (or 'exit' to quit): "; // Prompt for a word
        cin >> word; // Read the word from user
        if (word == "exit") break; // Exit if the user types "exit"

        cout << "Enter row and column (0-based): "; // Prompt for position
        cin >> row >> col; // Read the position from user
        cout << "Enter direction (h for horizontal, v for vertical): "; // Prompt for direction
        cin >> direction; // Read the direction from user

        // Determine if the direction is horizontal or vertical
        bool horizontal = (direction == 'h');
        
        // Try to add the word to the grid and display success or failure message
        if (crossword.addWord(word, row, col, horizontal)) {
            cout << "Word added successfully!" << endl; // Success message
        } else {
            cout << "Failed to add word. It may not fit or there may be conflicts." << endl; // Failure message
        }

        crossword.display(); // Display the updated grid
    }

    return 0; // Indicate that the program ended successfully
}
