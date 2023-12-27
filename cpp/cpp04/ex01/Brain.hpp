# ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {
private:
    std::string ideas[100];

public:
    std::string getIdeas(unsigned int idx);
    void setIdeas(unsigned int idx, std::string str);
    Brain();
    Brain(const Brain &Brain);
    Brain &operator=(const Brain& Brain);
    ~Brain( void );
};

#endif
