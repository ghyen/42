#include "ShrubberyCreationForm.hpp"

void ShrubberyCreatiohnForm::execute(Bureaucrat const &executor)
{
	std::string fileName = getName().append("_shrubbery");
	std::ofstream fs(fileName);
    if(!fs)
    {
        std::cerr<<"Cannot open the output file."<<std::endl;
        return ;
    }

    fs<<R"(
                                               .
                                   .         ;  
      .              .              ;%     ;;   
        ,           ,                :;%  %;   
         :         ;                   :;%;'     .,   
,.        %;     %;            ;        %;'    ,;
  ;       ;%;  %%;        ,     %;    ;%;    ,%'
   %;       %;%;      ,  ;       %;  ;%;   ,%;' 
    ;%;      %;        ;%;        % ;%;  ,%;'
     `%;.     ;%;     %;'         `;%%;.%;'
      `:;%.    ;%%. %@;        %; ;@%;%'
         `:%;.  :;bd%;          %;@%;'
           `@%:.  :;%.         ;@@%;'   
             `@%.  `;@%.      ;@@%;         
               `@%%. `@%%    ;@@%;        
                 ;@%. :@%%  %@@%;       
                   %@bd%%%bd%%:;     
                     #@%%%%%:;;
                     %@@%%%::;
                     %@@@%(o);  . '         
                     %@@@o%;:(.,'         
                 `.. %@@@o%::;         
                    `)@@@o%::;         
                     %@@(o)::;        
                    .%@@@@%::;         
                    ;%@@@@%::;.          
                   ;%@@@@%%:;;;. 
               ...;%@@@@@%%:;;;;,.. )";
    fs.close();
}

ShrubberyCreatiohnForm::ShrubberyCreatiohnForm() : AForm("", 150) {}
ShrubberyCreatiohnForm::ShrubberyCreatiohnForm(std::string name) : AForm(name, 150) {}
ShrubberyCreatiohnForm::ShrubberyCreatiohnForm &operator=(const ShrubberyCreatiohnForm& SCForm)
{

}
void ShrubberyCreatiohnForm::~AForm( void )
{

}