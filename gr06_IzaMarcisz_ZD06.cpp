#include <iostream>

using namespace std;

struct Product {
  string name;
  string brand;
  double price;
  double weight;
  double carbohydrates;
  double proteins;
  double fats;

  Product(string n = "Name", string b = "Brand", double p = 0, double w = 0, double c = 0, double pr = 0, double f = 0) {
    name = n;
    brand = b;
    price = p;
    weight = w;
    carbohydrates = c;
    proteins = pr;
    fats = f;
  }
  void set_info(string n, string b, double p, double w, double c, double pr, double f) {
    name = n;
    brand = b;
    price = p;
    weight = w;
    carbohydrates = c;
    proteins = pr;
    fats = f;
  }
  double calories() {
    carbohydrates = carbohydrates / 100;
    proteins = proteins / 100;
    fats = fats / 100;

    return ( weight * ((carbohydrates * 4) + (proteins * 4) + (fats * 9)) );
  }
  void printInfo() {
    cout << name << ", " << brand << "\n";
    cout << "   Price: " << price << " zl " << "  Weight: " << weight << " g";
    cout << "\n   Carbohydrates (in %): " << carbohydrates << " " << "  Proteins (in %): " << proteins << " " << "  Fats (in %): " << fats;
    cout << "\n   Calories in one unit: " << calories() << " kcal\n\n";
  }
};

class ShoppingList {
private:
  string list_name;
//  const double budget = 100;
  Product *ptr_product[4];
public:

};

int main() {

  Product *products = new Product[5];

  products[1].set_info("Makaron świderki", "Lubella", 3.99, 125, 13, 69, 0); 
  products[2].set_info("Czekolada mleczna", "Milka", 4.19, 100, 7, 60, 30); 
  products[3].set_info("Chipsy solone", "Lay's", 5.29, 185, 6, 52, 32);
  products[4].set_info("Ketchup łagodny", "Pudliszki", 1.79, 60, 1, 35, 0);
  products[5].set_info("Ser Edamski", "Serenada", 5.39, 150, 26, 1, 27);

  for(int i = 1; i <= 5; i++) {
    cout << "Product " << i << ": ";
    products[i].printInfo();
  }

  string Product::*ptr_name; 
  ptr_name = & Product::name;

  double (Product::*ptr_calories) ();
  ptr_calories = & Product::calories;

  cout << "Name and calories of the last product (using pointers): " << products[5].*ptr_name << " " << (products[5].*ptr_calories)() * 100 << " kcal\n"; //nie wiem dlaczego wywala mi tutaj zla wartosc, poprawic

  ShoppingList list1;

  return 0;
}