
#ifndef EMPRUNT_H_
#define EMPRUNT_H_

#include <string>
using namespace std;


class Emprunt{

private:
	Adherent _adherent;
	Article _article;
	string _date_emprunt;
	string  _date_retour;

public:

    /*getters*/

	const Adherent & get_adherent()const{
		return _adherent;
	}

	const Article & get_article()const{
		return _article;
	}

	const string & get_date_emprunt()const{
		return _date_emprunt;
	}

	const string & get_date_retour()const{
		return _date_retour;
	}

	/*setters*/

		void set_adherent(const Adherent & adherent){
			 _adherent=adherent;
		}

		void set_article(const Article & article ){
			 _article=article;
		}

		void set_date_emprunt(const string & date_emprunt){
			 _date_emprunt=date_emprunt;
		}

		void  set_date_retour(const string & date_retour){
			 _date_retour=date_retour;
		}


};


#endif /* EMPRUNT_H_ */
