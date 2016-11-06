#ifndef ARTICLE_H_
#define ARTICLE_H_

#include <string>
using namespace std;



class Article{

private:
   int 	_id;
   string _titre;
   bool _empruntable;
   int _exemplaire;
   int _duree_max;
   string _genre;
   string _type;



public:



   /*getters*/
   int get_id()const{
	   return _id;
   }
   const string & get_titre()const{
	   return _titre;
   }

   bool get_empruntable()const{
	   return _empruntable;
   }

   int get_exemplaire()const{
	   return _exemplaire;
   }

   int get_duree_max()const{
	   return _duree_max;
   }

   const string & get_genre()const{
	   return _genre;
   }

   const string & get_type()const{
	   return _type;
   }
   /*setters*/

   void set_id( int id){
  	   _id=id;
    }

    void set_titre( const string & titre){
	   _titre=titre;
   }

   void set_empruntable(bool empruntable){
	    _empruntable=empruntable;
   }

    void set_exemplaire(int exemplaire){
	    _exemplaire=exemplaire;
   }

   void set_duree_max(int duree_max){
	   _duree_max=duree_max;
   }

   void set_genre(const string & genre){
	    _genre=genre;
   }

   void set_type(const string & type){
	    _type=type;
   }

};


#endif /* ARTCILE_H_ */
