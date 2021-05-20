#include <iostream>
#include <string>
#include <fstream>
#include "Movies.hpp"

Movies* Movies::instance = nullptr;

void create_movies_from_file(){
    std::string line;
    std::ifstream movie_names_file ("movie_names.txt");
    if(movie_names_file.is_open()){
        while(std::getline(movie_names_file, line)){
            Movies* movies = Movies::get_movies_instance();
            movies->add_movie(line);
        }
    }
    else{
        std::cout << "cannot open file" << std::endl;
    }
}

void debug_create_movies(){
    Movies* movies = Movies::get_movies_instance();

    std::string name = "Holes";
    std::string genre = "Adventure";
    unsigned int rating {7};
    unsigned int watch_count {5};
    movies->add_movie(name, genre, rating, watch_count);

    name = "Mulan and the girl";
    genre = "Animation";
    rating = 8;
    watch_count = 9;
    movies->add_movie(name, genre, rating);

    name = "Flubber";
    genre = "Comedy";
    movies->add_movie(name, genre);

    name = "Nancy Drew";
    genre = "Crime/Mystery";
    movies->add_movie(name, genre);

}

void pause_execution(){
    std::string test;
    std::cin >> test;
}

int main(){
    create_movies_from_file();
    Movies* movies = Movies::get_movies_instance();
    std::string name {"The Dark Knight (2008)"};
    std::string name1 {"da"};
    std::string genre {"Action"};
    unsigned int rating { 10 };
    unsigned int watched_count { 100 };
    //movies->search_movie(name1);
    movies->update_genre(name, genre);
    movies->update_rating(name, rating);
    movies->update_watched(name, watched_count);
    //movies->search_movie(name);
    std::string user_input {"dark"};
    movies->search_movie(user_input);
    /* do{
        std::cout << "Enter search word: " ;
        std::cin >> user_input;
        movies->search_movie(user_input);
    } while (user_input != "q"); */
    //pause_execution();
    std::string dark_knight {"The Dark Knight (2008)"};
    movies->delete_movie(dark_knight);
    movies->search_movie(user_input);
    return 0;
}