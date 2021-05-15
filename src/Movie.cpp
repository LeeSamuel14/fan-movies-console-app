#include "Movie.hpp"

Movie::Movie(std::string n, std::string g, unsigned int r, unsigned w)
    :name{n}, genre{g}, rating{r}, watched_count{w} {  

}

/* Movie::Movie(const Movie& source)
    :Movie{source.name, source.genre, source.rating, source.watched_count} {

}*/

/*Movie::Movie(Movie&& source)
    :Movie{source.name, source.genre, source.rating, source.watched_count} {
} */

/* Movie::~Movie(){
    std::cout << "I am called";
} */

std::string Movie::get_name(){
    return name;
}

std::string Movie::get_genre(){
    return genre;
}

unsigned int Movie::get_rating(){
    return rating;
}

unsigned int Movie::get_watched_count(){
    return watched_count;
}

bool Movie::set_rating(unsigned int r){
    rating = r;
    return true;
}

bool Movie::set_watched_count(unsigned int w){
    watched_count = w;
    return true;
}