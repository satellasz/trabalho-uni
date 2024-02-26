#include <string>
#include <vector>
#include <iostream>;
#include <fstream>
#include <sstream>
#include "ValoresDefinidos.h"
#include "PessoaRepository.h"

using namespace std;

class PessoaService
{
	PessoaRepository pessoaRepository;
public:
	PessoaService(PessoaRepository pessoaRepostiroy) {
		this->pessoaRepository = pessoaRepostiroy;
	}
	void cadastrarPessoa() {
		ValoresDefinidos valoresDefinidos;
		std::string nome;

		string idade;
		int idadeConvertida;

		string altura;
		double alturaConvertida;

		string peso;
		double pesoConvertido;

		double imc;

		cout << "Digite o nome: ";
		cin.ignore();
		getline(cin, nome);

		while (true) {
			cout << "Digite a idade: ";
			idadeConvertida = pegarInputValidoInt(idade, "Digite a idade: ");

			if (idadeConvertida > idadeMaxima) {
				cout << "Idade ultrapassada." << endl;
			}
			else if (idadeConvertida < idadeMinima) {
				cout << "Idade inferior a " << idadeMinima << "." << endl;
			}
			else {
				break;
			}
		}

		while (true) {
			cout << "Digite a altura: ";
			alturaConvertida = pegarInputValidoDouble(altura, "Digite a altura: ");

			if (alturaConvertida > alturaMaxima) {
				cout << "Altura ultrapassada." << endl;
			}
			else {
				break;
			}
		}

		while (true) {
			cout << "Digite o peso: ";
			pesoConvertido = pegarInputValidoDouble(peso, "Digite o peso: ");

			if (pesoConvertido > pesoMaximo) {
				cout << "Peso ultrapassado." << endl;
			}
			else {
				break;
			}

		}
		
		Pessoa pessoa(nome, idadeConvertida, pesoConvertido, alturaConvertida);
		if (fazerValidacoes(pessoa)) {
			pessoaRepository.salvarPessoaDB(pessoa);
		}
		else {
			cout << "Informacoes invalidas" << endl;
		}

		cout << "--------------------------------" << endl;
	}

	void listarPessoasCadastradas() {
		vector<Pessoa> listaPessoas = pessoaRepository.pegarPessoasCadastradas();
		for (int c = 0; c < listaPessoas.size(); c++) {
			mostrarInformacoesPessoa(listaPessoas.at(c));
			cout << "--------------------------------" << endl;
		}
		
	}

	
	void listarPessoaPorNome(std::string nome) {
		if (pessoaRepository.pessoaExisteNoDB(nome)) {
			Pessoa pessoa = pessoaRepository.listarPessoaPorNome(nome);
			mostrarInformacoesPessoa(pessoa);
		}
		else {
			cout << "Pessoa nao consta no banco." << endl;
		}

		cout << "--------------------------------" << endl;
	}

	
	void mostrarInformacoesPessoa(Pessoa pessoa) {
		cout << "Nome: " << pessoa.nome << endl;
		cout << "Idade: " << pessoa.idade << " anos" << endl;
		cout << "Peso: " << pessoa.peso << "kg" << endl;
		cout << "Altura: " << pessoa.altura << "m" << endl;
		cout << "IMC: " << pessoa.imc << endl;
	}

	bool fazerValidacoes(Pessoa pessoa) {
		bool sucesso = false;
		if (pessoa.idade > idadeMinima && pessoa.idade < idadeMaxima) {
			if (pessoa.altura <= alturaMaxima) {
				if (pessoa.peso < pesoMaximo) {
					sucesso = true;
				}
			}
		}

		return sucesso;
	}

	int pegarInputValidoInt(string input, string display) {
		int inputValido;
		while (true) {
			cin >> input;
			std::istringstream iss(input);
			char remaining;

			if (!(iss >> inputValido && !(iss >> remaining))) {
				cout << "Campo aceita apenas numeros." << endl;
				cout << display;
			}
			else {
				break;
			}
		}

		return inputValido;
	}

	double pegarInputValidoDouble(string input, string display) {
		double inputValido;
		while (true) {
			cin >> input;
			std::istringstream iss(input);
			char remaining;

			if (!(iss >> inputValido && !(iss >> remaining))) {
				cout << "Campo aceita apenas numeros." << endl;
				cout << display;
			}
			else {
				break;
			}
		}

		return inputValido;
	}

};

