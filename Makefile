all: ordenacao4

ordenacao: ordenacao4.cpp
	@echo "Compilando arquivo objeto: ordenacao"
	@g++ -o ordenacao4 ordenacao4.cpp

install: ordenacao4
	@echo "Instalando no Sistema."
	@sudo cp ordenacao4 /usr/local/bin/ordenacao4

clean:
	@echo "Limpando arquivos"
	-@rm -f ordenacao4
