// Simu_Banque.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
#include <iostream>
#include<string>
#include<fstream>
using namespace std;

class CompteBancaire
{
private:
	string nom; //Nom du titulaire
	double solde; // Solde du compte bancaire

public:

	CompteBancaire():nom(""), solde(0.0) {} // Constructeur par défaut

	CompteBancaire(string n, double s) :nom(n), solde(s) {} // Constructeur avec paramètres

	void deposer(double montant) // Dépot d'argent sur le compte
	{
		solde += montant;
	}

	void retirer(double montant) // Retrait d'argent sur le compte
	{
		solde -= montant;
	}

	void afficherSolde() const // Affichage du solde du compte
	{
		cout << "Le solde est de : " << solde << " $. " << endl;
	}

	string setNom(string name)
	{
		nom = name;
	}

	string getNom() const // Affichage du nom du titulaire du compte
	{
		return nom;
	}

	bool estVide() const // Vérification si le compte est vide
	{
		if (solde == 0)
		{
			return true;
		}
	}

};

class Banque : private CompteBancaire
{
public:
	int compteur; // Compteur pour suivre le nombre de compte créés
	//CompteBancaire* comptes = new CompteBancaire[compteur]; // Tableau statique de compte bancaire
	CompteBancaire comptes[100];
	Banque() :compteur(0){}

	void creerCompte(string nom, double solde_initial = 0.0)
	{
		cout << " Veuillez entrer votre nom : ";
		cin >> nom;
		comptes[compteur] = CompteBancaire(nom, solde_initial);
		cout << "Le solde initial de votre compte est de : " << solde_initial << " $. " << endl;
		compteur++;
	}

	void deposer(string nom, double montant)
	{
		for (int i = 0; i < compteur; i++)
		{
			if (comptes[i].getNom() == nom)
			{
				cout << "Quel montant voulez-vous deposer sur votre compte ? " << endl << "Montant : ";
				cin >> montant;
				comptes[i].deposer(montant);
				cout << "Votre compte a ete debiter de " << montant << " $. " << endl;
				return;
			}
		}
		cout << "Compte non trouve. " << endl;
		
	}

	void retirer(string nom, double montant)
	{
		for (int i = 0; i < compteur; i++)
		{
			if (comptes[i].getNom() == nom)
			{
				cout << " Quel montant voulez-vous retirer de votre compte ? " << endl << "Montant : ";
				cin >> montant;
				comptes[i].retirer(montant);
				cout << "Votre compte a ete crediter de " << montant << " $. " << endl;
				return;
			}
		}
		cout << "Compte non trouve. " << endl;
	}

	void afficherSolde(string nom)
	{
		for (int i = 0; i < compteur; i++)
		{
			if (comptes[i].getNom() == nom)
			{
				comptes[i].afficherSolde();
			}
		}
	}
};



int main()
{
	int n,choix1,i=0;
	double montant = {};
	string anarana;
	Banque banque;
	
	banque.creerCompte("",0);

	do
	{
		cout << "Menu : " << endl;
		cout << "1. Creer un compte " << endl;
		cout << "2. Deposer de l'argent " << endl;
		cout << "3. Retirer de l'argent " << endl;
		cout << "4. Afficher le solde " << endl;
		cout << "5. Quitter " << endl;
		cin >> choix1;

		switch (choix1)
		{
			case 1:
			{
				banque.creerCompte("", 0);
				break;
			}
			case 2:
			{
				cout << "Quel est votre nom : ";
				cin >> anarana;
				banque.deposer(anarana, montant);
				
				//while(anarana!=)
				//banque.deposer();
				break;
			}
			case 3:
			{
				cout << "Quel est votre nom : ";
				cin >> anarana;
				banque.retirer(anarana, montant);
				
				break;
			}
			case 4:
			{
				cout << "Quel est votre nom : ";
				cin >> anarana;
				banque.afficherSolde(anarana);
				break;
			}
		}
		i++;
	} while (i < 20);

	
}
