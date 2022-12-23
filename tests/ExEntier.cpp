#include <iostream>

class Entier
{
    private:
        int e; 
    public:
        Entier() {
            e = 0;
        }
        Entier(int e) {
            this->e = e; 
        }
        void affiche() const
        {
            std::cout << this->e << std::endl;
        } 
} ;

int main(){
    Entier e1;
    e1.affiche(); // affiche 0
    
    int i = 1;
    Entier e2 = i; e2.affiche(); // affiche 1

    Entier e3 = '1';
    e3.affiche(); // 
}

