// Simu_Banque.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
#include <iostream>
#include<string>
#include<fstream>
#include<cstdlib>
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
	
	double getSolde() const // Affichage du solde du compte
	{
		return solde;
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

struct Noeud
{
	CompteBancaire comptes;
	Noeud* suivant;
};

class Banque : private CompteBancaire
{
private:
	Noeud* tete;
public:
	int compteur; // Compteur pour suivre le nombre de compte créés
	
	Noeud* creerNoeud(CompteBancaire comptes) // Création de noeud
	{
		Noeud* nouveauNoeud = new Noeud();
		nouveauNoeud->comptes = comptes;
		nouveauNoeud->suivant = nullptr;
		return nouveauNoeud;
	}

	void ajouterCompte( CompteBancaire comptes) // Créer un nouveau compte en utilisant un nouveau noeud
	{
		Noeud* nouveauNoeud = creerNoeud(comptes);
		nouveauNoeud->suivant = tete;
		tete = nouveauNoeud;
	}

	void creerCompte() // Ajout du nom lors de la création du compte
	{
		string nom;
		double solde_initial = 0.0;

		cout << " Veuillez entrer votre nom : ";
		cin >> nom;
		cout << "Le solde initial de votre compte est de : " << solde_initial << " $. " << endl;

		CompteBancaire comptes(nom, solde_initial);
		ajouterCompte(comptes);
		compteur++;
	}

	void deposer(string nom, double montant) // Dépôt d'argent dans le solde du compte
	{
		Noeud* temp = tete;

		while (temp != nullptr)
		{
			if (temp->comptes.getNom() == nom)
			{
				cout << "Quel montant voulez-vous deposer sur votre compte ? " << endl << "Montant : ";
				cin >> montant;
				temp->comptes.deposer(montant);
				cout << "Votre compte a ete crediter de " << montant << " $. " << endl;
				return;
			}
			temp = temp->suivant;
		}
		cout << "Compte non trouve. " << endl;
		
	}

	void retirer(string nom, double montant) // Retrait d'argent du compte
	{
		Noeud* temp = tete;

		while (temp != nullptr)
		{
			if (temp->comptes.getNom() == nom)
			{
				cout << "Quel montant voulez-vous retirer sur votre compte ? " << endl << "Montant : ";
				cin >> montant;
				temp->comptes.retirer(montant);
				cout << "Votre compte a ete debiter de " << montant << " $. " << endl;
				return;
			}
			temp = temp->suivant;
		}
		cout << "Compte non trouve. " << endl;
	}

	void afficherSolde(string nom) // Affichage du solde du compte
	{
		Noeud* temp = tete;

		while (temp!=nullptr)
		{
			if (temp->comptes.getNom() == nom)
			{
				temp->comptes.afficherSolde();
				return;
			}
			temp = temp->suivant;
		}
	}

	void afficherListe() // Affiche tout les comptes bancaires existants et enregistrés
	{
		Noeud* temp = tete;
		cout << "Liste des comptes bancaires existants : " << endl;

		while (temp != nullptr)
		{			
			cout <<"Nom : " << temp->comptes.getNom() << " \n";
			cout << "Solde : " << temp->comptes.getSolde() << " $." << endl<< endl;
			temp = temp->suivant;
		}
	}

	void copieFichier() // Enregistrement du Nom et du solde d'un compte dans un fichier txt
	{
		fstream monFichier("listeComptes.txt", ios::out |ios ::app);
		Noeud* temp = tete;
		
		while (temp != nullptr)
		{
			monFichier << "Nom : " << temp->comptes.getNom() << " \n";
			monFichier << "Solde : " << temp->comptes.getSolde() << " $." << endl << endl;
			temp = temp->suivant;
		}
		monFichier.close();
	}

	
};

void viderFichier(const string& nomFichier) // Vide totalemtn le fichier
{
	ofstream monFichier(nomFichier, ios::out);
	monFichier.close();
}

int main()
{
	int n,choix1,i=0;
	double montant = {};
	string anarana,choix2;
	Banque banque;
	Noeud* tete = nullptr;
	
	do
	{
		cout << "Menu : " << endl;
		cout << "1. Creer un compte " << endl;
		cout << "2. Deposer de l'argent " << endl;
		cout << "3. Retirer de l'argent " << endl;
		cout << "4. Afficher le solde " << endl;
		cout << "5. Afficher tout les comptes " << endl;
		cout << "6. Enregistrer dans un fichier " << endl;
		cout << "7. Vider le fichier " << endl;
		cout << "8. Quitter \n Reponse : " ;
		cin >> choix1;

		switch (choix1)
		{
			case 1:
			{
				banque.creerCompte();
				break;
			}
			case 2:
			{
				cout << "Quel est votre nom : ";
				cin >> anarana;
				banque.deposer(anarana, montant);
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
			case 5:
			{
				banque.afficherListe();
				break;
			}
			case 6:
			{
				banque.copieFichier();
				break;
			}
			case 7:
			{
				viderFichier("listeComptes.txt");
				cout << "Le fichier a ete vide." << endl;
				break;
			}
			case 8:
			{
				exit(0);
			}
			default:
			{
				cout << "Choix invalide, veuillez reessayer. " << endl;
			}
		}
		cout << "Voulez-vous continuer : Oui / Non \nReponse : ";
		cin >> choix2;
		i++;
	} while (choix2=="Oui");

	cout << "\n====== Au revoir ! ======" << endl;
	return 0;
}
