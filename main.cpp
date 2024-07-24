#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>


struct Candidato {
    std::string nombre;
    std::string partidoPolitico;
    int votos;
};


std::vector<Candidato> candidatos;


void registrarCandidato() {
    Candidato candidato;
    std::cin.ignore();  
    std::cout << "Ingrese el nombre del candidato: ";
    std::getline(std::cin, candidato.nombre);
    std::cout << "Ingrese el partido politico del candidato: ";
    std::getline(std::cin, candidato.partidoPolitico);
    candidato.votos = 0;
    candidatos.push_back(candidato);
    std::cout << "Candidato registrado exitosamente.\n";
}


void votar() {
    if (candidatos.empty()) {
        std::cout << "No hay candidatos registrados.\n";
        return;
    }

    std::cout << "Lista de candidatos:\n";
    for (size_t i = 0; i < candidatos.size(); ++i) {
        std::cout << i + 1 << ". " << candidatos[i].nombre << " (" << candidatos[i].partidoPolitico << ")\n";
    }

    std::cout << "Ingrese el numero del candidato para votar: ";
    size_t opcion;
    std::cin >> opcion;

    if (opcion > 0 && opcion <= candidatos.size()) {
        candidatos[opcion - 1].votos++;
        std::cout << "Voto registrado exitosamente.\n";
    } else {
        std::cout << "Opcion invalida.\n";
    }
}


void mostrarResultados() {
    if (candidatos.empty()) {
        std::cout << "No hay candidatos registrados.\n";
        return;
    }

    int totalVotos = 0;
    for (const auto& candidato : candidatos) {
        totalVotos += candidato.votos;
    }

    std::cout << "Resultados de la eleccion:\n";
    for (const auto& candidato : candidatos) {
        double porcentaje = (totalVotos > 0) ? (static_cast<double>(candidato.votos) / totalVotos) * 100 : 0.0;
        std::cout << candidato.nombre << " (" << candidato.partidoPolitico << ") - " 
                  << candidato.votos << " votos (" << std::fixed << std::setprecision(2) << porcentaje << "%)\n";
    }

    auto ganador = std::max_element(candidatos.begin(), candidatos.end(), [](const Candidato& a, const Candidato& b) {
        return a.votos < b.votos;
    });

    if (ganador != candidatos.end()) {
        std::cout << "El ganador es: " << ganador->nombre << " con " << ganador->votos << " votos.\n";
    }
}


void mostrarMenu() {
    std::cout << "\nSistema de Votaciones Electronico\n";
    std::cout << "1. Ingresar Candidatos\n";
    std::cout << "2. Votaciones\n";
    std::cout << "3. Resultados\n";
    std::cout << "4. Salir\n";
    std::cout << "Ingrese su opicon: ";
}


int main() {
    int opcion;
    do {
        mostrarMenu();
        std::cin >> opcion;
        switch (opcion) {
            case 1:
                registrarCandidato();
                break;
            case 2:
                votar();
                break;
            case 3:
                mostrarResultados();
                break;
            case 4:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << " Intente de nuevo.\n";
        }
    } while (opcion != 4);
    return 0;
}
