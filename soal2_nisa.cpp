#include <iostream>
#include <string>

class Character {
private:
  std::string name;
  int health;
  int attackPower;

public:
  Character(std::string name, int health, int attackPower)
    : name(name), health(health), attackPower(attackPower) {}

  void attack(Character& target) {
    target.health -= attackPower;
    if (target.health < 0) target.health = 0;
  }

  bool isAlive() const { //bool itu true or false
    return health > 0;
  }

  void printStatus() const {
    std::cout << name << " has " << health << " health remaining.\n";
  }

  std::string getName() const {
    return name;
  }
};

int main() {
  // Input health dan attack power untuk Finn dan Ice King
  int finnHealth, finnAttack;
  int iceKingHealth, iceKingAttack;
  std::string firstTurn;

  std::cin >> finnHealth >> finnAttack;
  std::cin >> iceKingHealth >> iceKingAttack;
  std::cin >> firstTurn;

  // Buat objek dalam kelas karakter
  Character finn("Finn", finnHealth, finnAttack); //parameter dari konstruktor yg di atas
  Character iceKing("Ice King", iceKingHealth, iceKingAttack);

  // Cetak status awal
  finn.printStatus(); //memanggil fungsi untuk mencetak status finn
  iceKing.printStatus(); //memanggil fungsi untuk mencetak status ice king

  // Simulasi pertarungan
  while (finn.isAlive() && iceKing.isAlive()) {// loop terjadi selama kedua karakter masih isAlive
    if (firstTurn == "finn") { 
      std::cout << "Finn attacks Ice King!\n";
      finn.attack(iceKing); //memanggil fungsi untuk finn attack ice king
      iceKing.printStatus(); //memanggil fungsi untuk mencetak status ice King

      if (!iceKing.isAlive()) break;

      std::cout << "Ice King attacks Finn!\n";
      iceKing.attack(finn);
      finn.printStatus();
    } else { //kondisi first turnnya adalah ice King
      std::cout << "Ice King attacks Finn!\n";
      iceKing.attack(finn);
      finn.printStatus();

      if (!finn.isAlive()) break;

      std::cout << "Finn attacks Ice King!\n";
      finn.attack(iceKing);
      iceKing.printStatus();
    }
  }

  // Cetak pemenang
  if (finn.isAlive()) {
    std::cout << "Finn wins the battle!\n";
  } else {
    std::cout << "Ice King wins the battle!\n";
  }

  return 0;
}


