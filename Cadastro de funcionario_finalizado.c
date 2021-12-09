#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void welcome(){//primriro menu do sistema
    printf("\n-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n-=-=-=-=-=-            Bem vindo   -=-=-=-=-=-=-=-=-=-=");
    printf("\n-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
}

int menuarquivo(int resmenu){/*menu de escolha, caso tenha .txt vai ser lido se quiser ou não*/
    printf("\nJa tem algum .txt ?\t");
    printf("\n1 - Sim");
    printf("\n2 - Nao\n");
    scanf("%d",&resmenu);
    //resposta do menu vai para o int mani por meio de função
    return(resmenu);
}

void menu(){/*uns do menu principal aprece apos as opções do arquivo*/
    system("cls");
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    printf("\n-=-=-=-=-=-=-=   Cadastro de funcionario    -=-=-=-=-=-=-");
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n0 - sair do programa e gerar arquivo");
    printf("\n1 - Cadastrar novo funcionario ");
    printf("\n2 - Excluir cadastro ");
    printf("\n3 - Listar todos os funcionarios");
    printf("\n4 - Ordena por horas trabalhadas");
    printf("\n5 - Ordenar por ordem alfabetica");
}

typedef struct{/*struct principal com todos os dados solicitado pelo usuario*/
    char nome[50];
    int idade;
    int horas;
    int cod;
}cadastro;

int cadfuncionarios(cadastro cadfun[21], int tamanho){
int aux=0,res=0;
//função para cadastro de funcionario
    do{
        system("cls");
        printf("\n----------- Cadastro -----------\n");
        res = 0;
        //as linhas abaixo são ler as informações digitada pelo usuario
        printf("\nQual o nome do funcionario ?\t");
        setbuf(stdin,NULL);
        gets(cadfun[tamanho].nome);
        printf("Quantas horas trabalhadas ?\t");
        scanf("%d",&cadfun[tamanho].horas);
        printf("Qual a idade ?\t");
        scanf("%d",&cadfun[tamanho].idade);
        //aqui e gerado o codigo do cadastro de forma automatica 
        cadfun[tamanho].cod = tamanho;
        tamanho++;
        aux++;
    
    if(aux > 21){
        //caso os cadastro passe pelo numero maximo definido
        printf("\ncadastro de funcionario atigiu o limite maximo\n");
        system("pause");
        res = 0;
        break;
    }

    //perguntar para o usuario se ele quer cadastrar mais um funcionario
    printf("\nDeseja continuar a informa cadastro \n[1 - sim]\n[qualquer outra tecla para ''nao'']?\t");
    setbuf(stdin,NULL);
    scanf("%d",&res);
    
    //while caso o usuario digite uma opção invalida
    }while(res == 1);

    return (tamanho);
}

void imprimirfuncionarios(cadastro cadastro[21],int tamanho){
    //system("cls");
    //função para mostrar todos os funcionario cadastratado ate o momento da execução
    //mostra esse pequeno cabecario 
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    printf("\n-=-=-=-         Funcinarios cadastrados       -=-=-=-");
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

    
    for(int j = 0; j < tamanho;j++){
        //mostra todos os usuario cadastratado
        printf("\nNome do funcionario:  %s",cadastro[j].nome);
        printf("\nHoras trabalhada: %d",cadastro[j].horas);
        printf("\nIdade: %d",cadastro[j].idade);
        printf("\nCodigo do funcionario: %d",cadastro[j].cod);
        printf("\n============================================");
    }
printf("\n");
system("pause");
}

void horastrabalhadas(cadastro cadfun[21],int tamanh,cadastro cadhora[21]){
    //organizar por horas trabalhadas de forma crescente
    int aux;
    char auxtexto[50];

    /*copiando as informações da struct principal
    para fazer as comparações*/
    for (int i = 0; i < tamanh; i++){
        (cadhora[i].horas) = (cadfun[i].horas);
        strcpy((cadhora[i].nome),(cadfun[i].nome));
        (cadhora[i].idade) = (cadfun[i].idade);
    }
    
    //mostrar cabecario
    printf("\n--------------------------------------");
    printf("\n-- Organizado por horas trabalhadas --");
    printf("\n--------------------------------------");

    for(int i = 0; i < tamanh; i++){
        for(int j = (i+1); j < tamanh; j++){
            //if para organizar de forma crescente as horas trabalhadas
            if(cadhora[i].horas > cadhora[j].horas){
                aux = cadhora[i].horas;
                cadhora[i].horas =  cadhora[j].horas;
                cadhora[j].horas = aux;

                //arrumar os nomes corresponde a hora trabalhada
                strcpy(auxtexto,cadhora[i].nome);
                strcpy(cadhora[i].nome,cadhora[j].nome);
                strcpy(cadhora[j].nome,auxtexto);

                //arrumar idade a hora correspondente 
                aux = cadhora[i].idade;
                cadhora[i].idade = cadhora[j].idade;
                cadhora[j].idade = aux;    
                break;
            }
        }
    }
    

    for (int i = 0; i < tamanh; i++){
        printf("\nA(o) funcionaria(o) %s",cadhora[i].nome);
        printf("\nTrabalhou esse mes %d horas",cadhora[i].horas);
        printf("\nIdade: %d",cadhora[i].idade);
        printf("\n----------------------------");
    }
    printf("\n");
    system("pause");
}

void ordemalfabetica(cadastro cadfun[21],int tamanho,cadastro cadordem[21]){
//organizar em ordem alfabetica em forma crescente as letras
//cresncente indo a,b,c...
char auxtexto[50]; 
int aux;

    system("cls");
    //copiando as informações da struct principal
    //para fazer as comparações
    for (int i = 0; i < tamanho; i++){
        (cadordem[i].horas) = (cadfun[i].horas);
        strcpy((cadordem[i].nome),(cadfun[i].nome));
        (cadordem[i].idade) = (cadfun[i].idade);
    }

    for (int i = 0; i < tamanho; i++){
        for (int j = i; j < tamanho; j++){
            //usei o strcmp para fazer a organização em ordem alfabetica
            if(strcmp(cadordem[i].nome,cadordem[j+1].nome) < 0){
                strcpy(auxtexto,cadordem[i].nome);
                strcpy(cadordem[i].nome,cadordem[j].nome);
                strcpy(cadordem[j].nome,auxtexto);

                //arrumar horas em ordem crescente
                aux = cadordem[i].horas;
                cadordem[i].horas =  cadordem[j].horas;
                cadordem[j].horas = aux;

                //arrumar idade a hora correspondente 
                aux = cadordem[i].idade;
                cadordem[i].idade = cadordem[j].idade;
                cadordem[j].idade = aux;
                break;
            }
        }
    }

    //organiza e no final mostra como fica os nomes em ordem crescente
    printf("\n-----------------------------------------");
    printf("\n---- ordenado por ordem alfabetica ------");
    printf("\n-----------------------------------------");
    for (int i = 0; i < tamanho; i++){
        printf("\nFuncionario(a) %s",cadordem[i].nome);
        printf("\nHoras trabalhadas: %d",cadordem[i].horas);
        printf("\nIdade: %d",cadordem[i].idade);
        printf("\n----------------------------");
    }
}

int excluircad(cadastro cadfun[21], int tamanho){
//função para excluir um funcionario
int res;
    do{
        //mostra quais são os funcionarios cadastratado
        imprimirfuncionarios(cadfun,tamanho);
        //pergunta qual funcionario vai ser apagado
        printf("\nQual funcinario quer apagar ?");
        printf("\nDigite o codigo do funcionario:\t");
        setbuf(stdin,NULL);
        scanf("%d",&res);
        //caso o usuario digite um funcionario que não existe mostra a função
        if(((res < -1) || (res > tamanho))){
            printf("\nEsse funcionario nao existe");
        }else{
            //caso o funcionario exista a exclusão do funcionario sera feita 
            for(int i = 0; i < tamanho; i++){
                if(res == cadfun[i].cod){
                    for (int j = res+1; j < tamanho; j++){
                        (cadfun[i].horas) = (cadfun[j].horas);
                        strcpy((cadfun[i].nome),(cadfun[j].nome));
                        (cadfun[i].idade) = (cadfun[j].idade);
                        i++;
                    }
                    /*nos for acima ele esta comparado qual codigo o usuario digitou
                    apos achar um codigo que corresponde ao digitado pelo usuarioe vai fazer o 
                    processo de exclusão*/
                tamanho--;
                printf("\nfuncionarios apagado com successo");
                printf("\n");
                break;
                }
            }
        }

        break;
    //while caso digite uma função que não exista no codigo
    }while((res > -1) || (res < tamanho));
    return (tamanho);
}

void arquivo(cadastro cadfun[21], cadastro cadordem[21],cadastro cadhora[21],int tamanho){
    //função que gera um arquivo
    int res;
    FILE *pont_arq;
    //as opçoes que usuario pode salvar o arquivo
    printf("como vai querer salvar o arquivo ?\n1 - todos cadastro\n2 - ordem alfabetica\n3 - ordem trabalhadas\n4 - nao gravar nada\n");
    scanf("%d",&res);
    switch(res){
        //conforme a opção escolhida pelo o usuario 
        //ira entrar no case
        case 1://case 1 para salvar todos os usuarios cadastrado conforme foram cadastrado
            pont_arq = fopen("cadastro.txt","w");
            for(int i =0;i < tamanho;i++){
                fprintf(pont_arq,"%s;",cadfun[i].nome);
                fprintf(pont_arq,"%d;",cadfun[i].horas);
                fprintf(pont_arq,"%d\n",cadfun[i].idade);  
            }
        break;  

        case 2://case 2 para salvar os funcionarios em ordem alfabetica do nome
        pont_arq = fopen("cadastro.txt","w");
        for(int i =0;i < tamanho;i++){
                fprintf(pont_arq,"%s;",cadordem[i].nome);
                fprintf(pont_arq,"%d;",cadordem[i].horas);
                fprintf(pont_arq,"%d\n",cadordem[i].idade);
        }
        break;

        case 3://case 3 para salvar os funcionarios pelas as horas trabalhadas
        pont_arq = fopen("cadastro.txt","w");
        for(int i =0;i < tamanho;i++){
                fprintf(pont_arq,"%s;",cadhora[i].nome);
                fprintf(pont_arq,"%d;",cadordem[i].horas);
                fprintf(pont_arq,"%d\n",cadordem[i].idade);
        }
        break;
    
        default:
        printf("\nopcao invalidade\no programa ira fechar");
        break;
        fclose(pont_arq);
    }
    printf("\nTodos os dados ja foram salvos");
}


int main(){//main pricinpal que chama todos os outras funções 
    int tamanho = 0,resnum,resmenu;
    FILE* pont_arq;//função para usar/criar/ler arquivo
cadastro cadfun[21];
cadastro cadhora[21];
cadastro cadordem[21];
//as tres struct acima são as que uso no codigo sendo a cadfun para registro geral
//a cadhora para ordenar por horas trabalhadas 
//e a cadordem para ordenar em ordem alfabetica

do{
//caso o usuario digite uma opção invalida
    welcome();
    resmenu = menuarquivo(resmenu);
    int char_cnt,campo_cnt=0,linha_cnt=0;
    char c,campo[50];
    //essa parte agora e para ler um .txt caso o usuario tenha

    if(resmenu == 1){
        //apos o usuario escolher uma opção ele vira para ca caso tenha um arquivo .txt
        pont_arq = fopen("cadastro.txt","r");
        if(pont_arq == NULL){
            //caso de algum problema com a leitura do arquivo 
            //sera mostrada essa mensagem
            printf("Arquivo nao existe ou erro na leitura");
            printf("\n");
            system("pause");
        }

        if(pont_arq != NULL){
            //caso tenha um arquivo para leitura entra nessa opção
            do{
                /*para fazer a leitura do arquivo eu usei o metodo .csv e achei muito 
                interrsnte essa forma de exportação de dados e importação
                usei essa função para ler as informações no arquivo*/
                c = fgetc(pont_arq);
                char_cnt=0;
                //as informações sendo lido do .txt
                do{
                    campo[char_cnt] = c;
                    char_cnt++;
                    c = fgetc(pont_arq);
                } while ((c!=';') && (c!=EOF) && (c!='\n'));
            
                //sendo encerrida na struct correspondente
                if(campo_cnt == 0){
                    strcpy(cadfun[linha_cnt].nome,campo);
                }else if(campo_cnt == 1){
                    cadfun[linha_cnt].horas = atoi(campo);
                }else if(campo_cnt == 2){
                    cadfun[linha_cnt].idade = atoi(campo);
                }
                
                //fazendo um teste para continuar a ler as coisas no arquivo
                if(c =='\n'){
                    campo_cnt = 0;
                    linha_cnt++;
                    cadfun[tamanho].cod = tamanho;
                    tamanho++;

                }else{
                    campo_cnt++;
                    
                }
            //quando chegar no final do arquico fazer comparação para sair do while
            }while(c != EOF);
            
        }
    //fechar o arquivo
    fclose(pont_arq);
    }

    
    if((resmenu == 1)||(resmenu == 2)){
    do{
        printf("%d",tamanho);
        menu(); 
        /*"setbuf" aqui para limpar caso o usuario digite uma letra e 
        guardar no buffer o valor de enter, ISSO EVITA BUGS*/
        setbuf(stdin,NULL);
        //escolher uma opção para entrar nas função
        printf("\nEscolha uma opcao:   ");
        scanf("%d",&resnum);
        system("cls");
        

        /*Como no menu de opções são usadas numeros para indicar a opção,
        eu achei melhor usar um "switch - case", eu poderia usar "ifs" para fazer 
        isso funcionar tambem, mas com "switch - case" fica mais organizado.*/
        switch (resnum){

            //opção 0 e para sair do programa e gravar arquivo
            case 0:
                arquivo(cadfun,cadordem,cadhora,tamanho);
                printf("\nVoce esta saindo do programa.");
                printf("\nAte a proxima");
                printf("\n");
                system("pause");
                return 0;
            break;

            case 1://cadastrar funcionario
                tamanho = cadfuncionarios(cadfun,tamanho);
                resnum = 100;
                system("pause");
                system("cls");
            break;

            case 2://excluir funcinario
                tamanho = excluircad(cadfun,tamanho);
                resnum = 100;
                system("pause");
                system("cls");
            break;

            case 3://mostrar todos os funcionarios
                printf("\ntamanho %d",tamanho);
                imprimirfuncionarios(cadfun,tamanho);
                resnum = 100;
                system("cls");
            break;

            case 4://organiozar e mostrar todos os funcionarios por horas trabalhadas
                horastrabalhadas(cadfun,tamanho,cadhora);
                resnum = 100;
                system("cls");
            break;

            case 5://organizar e mostrar os funcionario por ordem alfabatica
                ordemalfabetica(cadfun,tamanho,cadordem);
                printf("\n");                
                system("pause");
                resnum = 100;
            break;

            default://caso digite uma opção invalida
                system("cls");
                printf("\nOpcao invalida\n");
                resnum = 100;
            break;
        }
    //caso digite uma opção invalida
    }while ((resnum < 0)||(resnum > 6));
    }
system("cls");
printf("\nopcao invalida\n\n");
//caso digite uma opção invalida
}while ((resmenu < 1)||(resmenu > 2));

}


