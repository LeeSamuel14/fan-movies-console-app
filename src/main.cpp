#include <iostream>
#include <string>
#include "Movies.hpp"

Movies* Movies::instance = nullptr;

int main(){
    Movies* movies = Movies::get_movies_instance();
    std::string name = "Holes";
    std::string genre = "Adventure";
    unsigned int rating {7};
    unsigned int watch_count {5};
    movies->add_movie(name, genre, rating, watch_count);
    name = "Mulan and the girl";
    genre = "Animation";
    rating = 8;
    //watch_count = 9;
    movies->add_movie(name, genre, rating);
    name = "Flubber";
    genre = "Comedy";
    movies->add_movie(name, genre);
    name = "Nancy Drew";
    genre = "Crime/Mystery";
    movies->add_movie(name, genre);
    std::cout << " " << std::endl;
    name = "n";
    movies->search_movie(name);
    movies->display_all_movies();
    std::string test;
    std::cin >> test;
    return 0;
}