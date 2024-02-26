#include <string>;

class Pessoa
{
public:
	std::string nome;
	int idade;
	double peso;
	double altura;
	double imc;

	Pessoa(std::string nome, int idade, double peso, double altura) {
		this->nome = nome;
		this->idade = idade;
		this->altura = altura;
		this->peso = peso;
		this->imc = peso / (altura * altura);
	}

	Pessoa() {

	}
};

