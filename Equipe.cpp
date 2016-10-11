#include "Equipe.h"

Equipe::Equipe(vector<shared_ptr<Joueur>> joueur) : points(0), joueurs(joueur)
{}

Equipe::Equipe(vector<shared_ptr<Equipe>> e)
{}

