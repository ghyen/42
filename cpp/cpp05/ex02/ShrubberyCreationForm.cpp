#include "ShrubberyCreationForm.hpp"

void ShrubberyCreatiohnForm::execute(Bureaucrat const &executor) const
{
  if (!getSigned())
  	throw AForm::NotSignedException();
  if (executor.getGrade() > execStandard)
  	throw AForm::GradeTooLowException();
	std::string fileName = executor.getName().append("_shrubbery");
	std::ofstream fs(fileName);
    if(!fs)
      throw CanNotCopyException();

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

ShrubberyCreatiohnForm::ShrubberyCreatiohnForm() : AForm("", 150, 145, 137) {}
ShrubberyCreatiohnForm::ShrubberyCreatiohnForm(std::string name) : AForm(name, 150, 145, 137) {}
ShrubberyCreatiohnForm::ShrubberyCreatiohnForm(const ShrubberyCreatiohnForm &ref)
{

}

ShrubberyCreatiohnForm &ShrubberyCreatiohnForm::operator=(const ShrubberyCreatiohnForm& ref)
{

}
ShrubberyCreatiohnForm::~ShrubberyCreatiohnForm( void ) {}
const char *ShrubberyCreatiohnForm::CanNotCopyException::what() const throw()
{
  return "ERROR : Can not open file";
}