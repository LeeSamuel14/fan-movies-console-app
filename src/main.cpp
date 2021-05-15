#include <iostream>
#include <string>
#include "Movies.hpp"

Movies* Movies::instance = nullptr;

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
    Movies* movies = Movies::get_movies_instance();
    std::string search_string = "n";
    movies->search_movie(search_string);
    movies->display_all_movies();
    pause_execution();
    return 0;
}