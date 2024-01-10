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

    fs<< "(\n"
            "                                               .\n"
            "                                   .         ;  \n"
            "      .              .              ;%     ;;   \n"
            "        ,           ,                :;%  %;   \n"
            "         :         ;                   :;%;'     .,   \n"
            ",.        %;     %;            ;        %;'    ,;\n"
            "  ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
            "   %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
            "    ;%;      %;        ;%;        % ;%;  ,%;'\n"
            "     `%;.     ;%;     %;'         `;%%;.%;'\n"
            "      `:;%.    ;%%. %@;        %; ;@%;%'\n"
            "         `:%;.  :;bd%;          %;@%;'\n"
            "           `@%:.  :;%.         ;@@%;'   \n"
            "             `@%.  `;@%.      ;@@%;         \n"
            "               `@%%. `@%%    ;@@%;        \n"
            "                 ;@%. :@%%  %@@%;       \n"
            "                   %@bd%%%bd%%:;     \n"
            "                     #@%%%%%:;;\n"
            "                     %@@%%%::;\n"
            "                     %@@@%(o);  . '         \n"
            "                     %@@@o%;:(.,'         \n"
            "                 `.. %@@@o%::;         \n"
            "                    `)@@@o%::;         \n"
            "                     %@@(o)::;        \n"
            "                    .%@@@@%::;         \n"
            "                    ;%@@@@%::;.          \n"
            "                   ;%@@@@%%:;;;. \n"
            "               ...;%@@@@@%%:;;;;,..\n"
            ")\n";
    fs.close();
}

ShrubberyCreatiohnForm::ShrubberyCreatiohnForm() : AForm("", 145, 137) {}
ShrubberyCreatiohnForm::ShrubberyCreatiohnForm(std::string name) : AForm(name, 145, 137) {}
ShrubberyCreatiohnForm::ShrubberyCreatiohnForm(const ShrubberyCreatiohnForm &ref) : AForm(ref.getName(), 145, 137) {}
ShrubberyCreatiohnForm::~ShrubberyCreatiohnForm( void ) {}
const char *ShrubberyCreatiohnForm::FileOpenException::what() const throw()
{
  return "ERROR : Can not open file";
}
