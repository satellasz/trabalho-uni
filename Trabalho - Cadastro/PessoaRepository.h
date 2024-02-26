#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Pessoa.h";


using namespace std;

class PessoaRepository
{
public:
	void salvarPessoaDB(Pessoa pessoa) {
		std::ofstream arquivo;
		arquivo.open("pessoas.csv", std::ios::app);
		arquivo << pessoa.nome << ";";
		arquivo << pessoa.idade << ";";
		arquivo << pessoa.peso << ";";
		arquivo << pessoa.altura << ";";
		arquivo << pessoa.imc << std::endl;
		arquivo.close();

		cout << "Cadastro feito com sucesso!" << endl;
	}

	vector<Pessoa> pegarPessoasCadastradas() {
		string pessoaString[5];
		std::fstream arquivo;
		string linha;
		vector<Pessoa> listaPessoas;
		arquivo.open("pessoas.csv");

		while (getline(arquivo, linha)) {
			std::istringstream ss(linha);
			std::string detalhe;
			int c = 0;

			while (std::getline(ss, detalhe, ';')) {
				pessoaString[c] = detalhe;
				c++;
			}

			string nome = pessoaString[0];
			int idade = stoi(pessoaString[1]);
			double peso = stod(pessoaString[2]);
			double altura = stod(pessoaString[3]);
			Pessoa pessoa(nome, idade, peso, altura);
			listaPessoas.push_back(pessoa);
		}

		arquivo.close();
		return listaPessoas;
	}

	Pessoa listarPessoaPorNome(std::string nome) {
		vector<Pessoa> listaPessoas = pegarPessoasCadastradas();
		Pessoa pessoa;
		for (int c = 0; c < listaPessoas.size(); c++) {
			if (listaPessoas.at(c).nome == nome) {
				pessoa = listaPessoas.at(c);
				break;
			}
		}

		return pessoa;
	}

	bool pessoaExisteNoDB(std::string nome) {
		vector<Pessoa> listaPessoas = pegarPessoasCadastradas();
		bool encontrouPessoa = false;
		for (int c = 0; c < listaPessoas.size(); c++) {
			if (listaPessoas.at(c).nome == nome) {
				encontrouPessoa = true;
				break;
			}
		}

		return encontrouPessoa;
	}
};

