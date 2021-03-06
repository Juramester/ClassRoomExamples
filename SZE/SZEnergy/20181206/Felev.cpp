#include "Felev.hpp"

Felev::Felev(int ev, std::string evszak) :ev(ev),evszak(evszak){}
  
int Felev::getEv() const { return ev; }
std::string Felev::getEvszak() const { return evszak; }

void Felev::addTargy(const Targy& t) {
  targyak.add(t);
}

bool Felev::hasTargy(const Targy& t) const {      
  return targyak.has(t);
}    


bool Felev::assignHallgato(const Targy& t, const Hallgato& h){
  if(!targyak.has(t)) return false;
  else {
    targyak.get(t).addHallgato(h);
  }
}


void Felev::printTargyak(std::ostream& s) const {
  s << targyak;
}

std::ostream& operator<<(std::ostream& s, const Felev& f){
  s<<f.getEv()<<" - "<<f.getEvszak()<<":"<<std::endl;
  f.printTargyak(s);
  return s;
}
