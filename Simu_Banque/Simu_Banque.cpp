// Simu_Banque.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
#include <iostream>
#include<string>
using namespace std;

class CompteBancaire
{
private:
	string nom; //Nom du titulaire
	double solde; // Solde du compte bancaire

public:

	CompteBancaire():nom(""), solde(0.0) {} // Constructeur par défaut

	CompteBancaire(string n, double s) // Constructeur avec paramètres
	{
		nom = n;
		solde = s;
	}

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

class Banque : public CompteBancaire
{
public:
	int compteur; // Compteur pour suivre le nombre de compte créés
	CompteBancaire* comptes = new CompteBancaire[compteur]; // Tableau statique de compte bancaire
	
	Banque() :compteur(0){}

	void creerCompte(string nom, double solde_initial = 0.0)
	{
		cout << " Veuillez entrer votre nom : ";
		cin >> nom;
		//comptes[compteur].setNom(nom);
		cout << "Le solde initial de votre compte est de : " << solde_initial << " $. " << endl;
		compteur++;
	}

	void deposer(string nom, double montant)
	{
		cout << "Quel montant voulez-vous deposer sur votre compte ? " << endl << "Montant : ";
		cin >> montant;
		comptes[compteur].deposer(montant);
		
	}

	void retirer(string nom, double montant)
	{
		cout << " Quel montant voulez-vous retirer de votre compte ? " << endl << "Montant : ";
		cin >> montant;
		comptes[compteur].retirer(montant);
	}

	void afficherSolde(string nom)
	{
		cout << "Nom : " << nom << endl;
	}
};


int main()
{
	int n;
	Banque compte;

	cout << "Combien de compte voulez-vous creer : ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		compte.creerCompte("",0);
	}
}
