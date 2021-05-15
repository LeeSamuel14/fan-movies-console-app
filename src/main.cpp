#include <iostream>
#include <string>
#include <fstream>
#include "Movies.hpp"

Movies* Movies::instance = nullptr;

void create_movies_from_file(){
    std::string line;
    std::ifstream my_file ("movie_names.txt");
    if(my_file.is_open()){
        while(std::getline(my_file, line)){
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
    std::string search_string = "man";
    movies->search_movie(search_string);
    //movies->display_all_movies();
    pause_execution();
    return 0;
}