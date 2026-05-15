#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Movie {
    std::string title;
    std::string genre;
};

int main() {
    std::vector<Movie> database = {
        {"The Dark Knight", "Action"}, {"Sherlock Holmes", "Mystery"},
        {"The Hangover", "Comedy"}, {"Interstellar", "Sci-Fi"},
        {"The Notebook", "Romance"},{"Avengers: Age of Ultron", "Action"}, 
		{"Zootopia", "Animated"}, {"Regretting You", "Romance"}
    };

    std::cout << "--- MOVIE RECOMMENDATION SYSTEM ---" << std::endl;
    std::cout << "Available Genres: Action, Sci-Fi, Comedy, Romance, Animated, Mystery" << std::endl;
    
    std::string choice;
    std::cout << "\nEnter your favorite genre: ";
    std::cin >> choice;
    std::transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

    bool found = false;
    std::cout << "\nBased on your preference, we suggest:" << std::endl;
    
    for (const auto& m : database) {
        std::string lowerGenre = m.genre;
        std::transform(lowerGenre.begin(), lowerGenre.end(), lowerGenre.begin(), ::tolower);
        
        if (lowerGenre == choice) {
            std::cout << ">> " << m.title << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "No matches for that genre. However, everyone loves 'The Hangover' (Comedy)!" << std::endl;
    }

    std::cout << "\nThank you for using our system!" << std::endl;
    return 0;
}
