#include <iostream>
#include <fstream>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atof */
#include <math.h>  
#include <stack>
#include <queue>

using namespace std;

#include "expression.h"

void expression::lecture(char* filename)
{
	char c;
	bool fin = false;

	filestream.open(filename);

	if(! filestream)
		cerr << "Erreur ouverture fichier" << filename << endl;
	else{
		cout << "Expr = ";

		// Lire caractère par caractère
		int nb_carac=0;

		while(!fin){
		
			filestream.seekg(nb_carac, filestream.beg); // lecture un caractere par caractere en partant du début du fichier
			filestream.get(c);
			if (int(c) == 102) {
				fin = true;}
				else
				{
				nb_carac++;	
				} 
			
			
				if (!fin) {
					// Afficher caractère lu
					cout << c;
					
					// Enfiler le caractère lu à la fin de la queue de la file FILE
					file.push(c); // Enfile ce caractère à la fin de la queue de la file
				}	
		
		
		} // Fin boucle while
		
		// cout << " (nbr de caractère: " << nb_carac << ")" << endl; // test affichage nbr caractere
		//cout << "\ncode ascii + " << int('+') << endl;  // ascii = 43
		//cout << "\ncode ascii - " << int('-') << endl;  // ascii = 45
		//cout << "\ncode ascii * " << int('*') << endl;  // ascii = 42
		//cout << "\ncode ascii / " << int('/') << endl;  // ascii = 47
		//cout << file.front(); // on récupére le premier élément


	}
	cout << endl;
	filestream.close();
}


double expression::calcul()
{
	
	double resultatCalcul;
	double resultatFinal;
	char valeur;
	int valeur_ascii;
	bool afficher_test=false;


		while( !(file.empty()) ){ // tant que la file n'est pas vide

			valeur = file.front(); // on obtient la valeur dans la queue de la file
			valeur_ascii = valeur;
			//cout << valeur;
			//cout << valeur_ascii;
			file.pop(); // 
			//return 0.0;



			// Si la valeur defilée est différente d'un opérateur
				if ( (valeur_ascii != 42) && (valeur_ascii != 43) && (valeur_ascii != 45) && (valeur_ascii != 47)  ) 
				{
					pile.push( (valeur - 48) );
					}else{
							// on réalise le calcul sur les 2 derniers éléments de la pile avec l'opérateur lu
							double valeur2= pile.top();
							pile.pop();

							double valeur1= pile.top();
							pile.pop();

							cout << valeur1 << char(valeur_ascii) << valeur2 << " = ";
								
								// Produit
								if (valeur_ascii == 42) 
								{
											resultatCalcul = valeur1 * valeur2;
											cout << resultatCalcul << endl;
											pile.push(resultatCalcul);
											resultatFinal = resultatCalcul;
											resultatCalcul=0;
								}

								// 

								// addition
								if (valeur_ascii == 43)
								{
											resultatCalcul = valeur1 + valeur2;
											cout << resultatCalcul << endl;
											pile.push(resultatCalcul);
											resultatFinal = resultatCalcul;
											resultatCalcul=0;
								}

								// 
								
								// soustraction
								if (valeur_ascii == 45)
								{ 
											resultatCalcul = valeur1 - valeur2;
											cout << resultatCalcul << endl;
											pile.push(resultatCalcul);
											resultatFinal = resultatCalcul;
											resultatCalcul=0;
								}

								// 

								// soustraction
								if (valeur_ascii == 47 && valeur2 != 0)
								{ 
									if (valeur2!=0){
											resultatCalcul = valeur1 / valeur2;
											cout << resultatCalcul << endl;
											pile.push(resultatCalcul);
											resultatFinal = resultatCalcul;
											resultatCalcul=0;
									}else{
										
										return(0);
									}
								}
								// 


						//file.front()
						//pile.top(); 
						//pile.pop();
						
						

					}




		}
		cout << endl;
		return resultatFinal;
}