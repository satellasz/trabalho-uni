#include <iostream>;
#include "PessoaService.h";

using namespace std;

class MenuController
{
private:
	void mostrarMenu() {
		cout << "Selecione a opcao desejada:" << endl;
		cout << "1 - Cadastrar pessoa" << endl;
		cout << "2 - Listar pessoas cadastradas" << endl;
		cout << "3 - Pesquisar pessoa por nome" << endl;
		cout << "4 - Sair" << endl;
	}

public:
	void iniciarFluxo() {
		PessoaRepository pessoaRepository;
		PessoaService pessoaService(pessoaRepository);
		while (true) {
			mostrarMenu();
			std::string nome;
			string opcao;
			int opcaoConvertida;
			cout << ">> ";
			cin >> opcao;

			cout << "--------------------------------" << endl;

			std::istringstream iss(opcao);
			char remaining;

			if (iss >> opcaoConvertida && !(iss >> remaining)) {
				switch (opcaoConvertida) {
				case 1:
					pessoaService.cadastrarPessoa();
					break;
				case 2:
					pessoaService.listarPessoasCadastradas();
					break;
				case 3:
					cout << "Buscar por nome: ";
					cin.ignore();
					getline(cin, nome);
					pessoaService.listarPessoaPorNome(nome);
					break;
				case 4:
					cout << "Saindo..." << endl;
					break;
				default:
					cout << "Opcao invalida." << endl;
					break;
				}

				if (opcaoConvertida == 4) {
					break;
				}
			}
			else {
				cout << "Opcao invalida." << endl;
			}
			
			
		}
	}
};

