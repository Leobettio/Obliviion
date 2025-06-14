#pragma once
#include "../Entidade.h"

class Jogador; // Forward declaration

namespace Obstaculos {

    class Obstaculo : public ::Entidade {
    protected:
        bool danoso; // Flag para indicar se o obstáculo causa dano

    public:
        Obstaculo();
        virtual ~Obstaculo();

        // Métodos virtuais puros que as classes filhas DEVERÃO implementar.
        // Note que estamos usando os nomes da nossa arquitetura base.
        virtual void update(float deltaTime) override = 0;
        virtual void handleCollision(Entidade& other) override = 0;
        virtual void salva() = 0; // Para o sistema de save futuro
    };

} 