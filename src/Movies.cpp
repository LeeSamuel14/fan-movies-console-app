#include "Movies.hpp"

Movies::Movies(){
    //asign movies here! //segmentation error was referenceing a null pointer
     movies = new std::vector<Movie*>;
     temp_movies = new std::vector<Movie*>;
}

Movies::~Movies(){
    instance = nullptr;
    for(size_t i { 0 }; i != movies->size(); ++i) {
        delete movies->at(i);
    }
    delete movies;
}

Movies* Movies::get_movies_instance(){
    if(instance == nullptr){
        instance = new Movies;
    }
    return instance;
}

void Movies::display_all_movies(){
     std::cout << "------  MOVIES  ------" << std::endl;
     std::cout << std::endl;
    for(size_t i { 0 }; i != movies->size(); ++i ){
        display_movie(movies->at(i));
    }
}
void Movies::display_movies_from_search(){
    for(size_t i { 0 }; i != temp_movies->size(); ++i ){
        std::cout << "("<< i+1 << ")" << std::endl;
        display_movie(temp_movies->at(i));
    }
}

void Movies::search_movie(std::string& movie_name){
    std::cout << "SEARCH RESULTS FOR \"" << movie_name << "\" :" << std::endl;
    std::cout <<  std::endl;
    bool found = compute_search(movie_name);
    if(found)
        display_movies_from_search();
    else
        std::cout << "NOT FOUND" << std::endl;
    temp_movies->clear();
}

void Movies::display_movie(Movie* movie){
    std::cout << "------  " << movie->get_name() << "  ------" << std::endl;
    std::cout << "Genre: " << movie->get_genre() << std::endl;
    std::cout << "Rating: " << movie->get_rating() << std::endl;
    std::cout << "Watched Count: " << movie->get_watched_count() << std::endl;
    std::cout << std::endl;
}

std::vector<Movie*>* Movies::get_movies(){
    return movies;
}

bool Movies::add_movie(const std::string& name,const std::string& genre, const unsigned int& rating,const unsigned int& watched_count){
    Movie* movie = new Movie{name, genre, rating, watched_count};
    movies->push_back(movie);
    return true;
}

bool Movies::add_movie(std::string& name, std::string& genre, unsigned int& rating){
    Movie* movie = new Movie{name, genre, rating};
    movies->push_back(movie);
    return true;
}

bool Movies::add_movie(std::string& name, std::string& genre){
    Movie* movie = new Movie{name, genre};
    movies->push_back(movie);
    return true;
}

bool Movies::add_movie(std::string& name){
    Movie* movie = new Movie{name};
    movies->push_back(movie);
    return true;
}

//pass it a vector<Movies*> return something think of a solution with delete

bool Movies::compute_search(std::string& search_string){
    std::vector<Movie*>::iterator movie_iterator { movies->begin() };
    
    while( (movie_iterator = std::find_if(movie_iterator, movies->end(), [&](Movie* movie) {

        std::string movie_name = movie->get_name();

        std::for_each(movie_name.begin(), movie_name.end(), [](char & s) {
            s = ::tolower(s);
        });
        std::for_each(search_string.begin(), search_string.end(), [](char & s) {
            s = ::tolower(s);
        });

        if (movie_name.find(search_string) != std::string::npos) {
            //try set flg here if you can
            return true;
        }
        else{
            return false;
        }

    } ) ) != movies->end() ){
        temp_movies->push_back(*movie_iterator);
        movie_iterator ++;
    }

   return ( temp_movies->size() > 0 );
}

bool Movies::update_genre(std::string& movie_name, std::string& genre){
    bool found = compute_search(movie_name);
    if(found){
        temp_movies->at(0)->set_genre(genre);
        temp_movies->clear();
        return true;
    }
    return false;
}

bool Movies::update_rating(std::string& movie_name, unsigned int& count){
    bool found = compute_search(movie_name);
    if(found){
        temp_movies->at(0)->set_rating(count);
        temp_movies->clear();
        return true;
    }
    return false;
}

bool Movies::update_watched(std::string& movie_name, unsigned int& count){
    bool found = compute_search(movie_name);
    if(found){
        temp_movies->at(0)->set_watched_count(count);
        temp_movies->clear();
        return true;
    }
    return false;
}

//WIP
bool Movies::delete_movie(std::string& movie_name_params){
    //bool found = compute_search(movie_name_params);
    if(true){
        std::vector<Movie*>::iterator it = std::find_if(movies->begin(), movies->end(), [&](Movie* movie) {

            std::string movie_name = movie->get_name();

            std::for_each(movie_name.begin(), movie_name.end(), [](char & s) {
                s = ::tolower(s);
            });
            std::for_each(movie_name_params.begin(), movie_name_params.end(), [](char & s) {
                s = ::tolower(s);
            });

            if (movie_name.find(movie_name_params) != std::string::npos) {
                //try set flg here if you can
                return true;
            }
            else{
                return false;
            }

        } );
        if (it != temp_movies->end()){
            delete *it;
            movies->erase(it);
            return true;
            } 
    }
    
    return false;
    /* bool found = compute_search(movie_name);
    if(found){
        if(temp_movies->size() > 0){
            movies->erase(getIndex(movie_name));
            delete temp_movies->at(0);
            temp_movies->clear();
        }
        
        temp_movies->clear();
        return true;
    }
    return false; */
}