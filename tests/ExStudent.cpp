#include <iostream>

class Student
{
    // Attributs
    private:
        int number;
        std::string surname;
    // Méthodes
    public:
        Student() {
            number = 0;
            surname = "NEW STUDENT";
        }
        void SetNumber(int n);
        int GetNumber() const;
        std::string ShowName() const ;
        void ShowStudent() const;
};

void Student::SetNumber(int n)
{
      number = n;
}

int Student::GetNumber() const
{
        return number;
}

std::string Student::ShowName() const
{
    return surname ;
}

void Student::ShowStudent() const
{
    std::cout << 
       this -> GetNumber() << 
       " > " << 
       this -> ShowName() << 
       std::endl;     
}

int main()           // arguments   
{ 
    Student st1 ;                  // Création d'une nouvelle instance (dans la pile)
    Student *pSt1 = &st1;          // Définition d'un pointeur sur une instance existante
    Student &st1ref = st1;         // Définition d'une référence sur une instance existante
    Student *pSt2 = new Student(); // Création d'une nouvelle instance (dans le tas), via un pointeur

    st1.ShowStudent();
    pSt2->ShowStudent();

    return 0;        // valeur de retour
} 



/*
    // Le constructeur initialise avec les valeurs par défaut (version pile)
    std::cout << 
       st1.GetNumber() << 
       " > " << 
       st1.ShowName() << 
       std::endl; 

    // Pareil, maintenant avec un pointeur (version tas)
    std::cout << 
       pSt2 -> GetNumber() << 
       " > " << 
       pSt2 -> ShowName() << 
       std::endl; 
*/
