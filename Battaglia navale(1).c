#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20
int campo1[N][N],campo2[N][N];
void posizionamento_navi(int);
void posizionamento_navi2(int);


int main() {
	int i,j,k,navi_max=6,lunghezza_nave,uno,partita_finita;
	srand(time(NULL));
	for(i=0;i<N;i++){
		for(j=0;j<N;j++)
			campo1[i][j]=0;
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++)
			campo2[i][j]=0;
	}		
	for(k=0;k<navi_max;k++){
		do{
			printf("Giocatore 1 inserisci la lunghezza della nave ");
			scanf("%d",&lunghezza_nave);
			posizionamento_navi(lunghezza_nave);
		}
		while(lunghezza_nave<=0 || lunghezza_nave>6);
	}
	for(k=0;k<navi_max;k++){
		do{
			printf("Giocatore 2 inserisci la lunghezza della nave ");
			scanf("%d",&lunghezza_nave);
			posizionamento_navi2(lunghezza_nave);
		}
		while(lunghezza_nave<=0 || lunghezza_nave>6);
	}
    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
            printf("%d",campo1[i][j]);
        printf("\n");    
    }
    printf("\n");
    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
            printf("%d",campo2[i][j]);
        printf("\n");    
    }   
	for(partita_finita=0;partita_finita==0;){
		printf("Giocatore 1 inserisci una posizione dove colpire(inserire riga e premere invio - inserire colonna e premere invio): ");
		scanf("%d",&i);
		scanf("%d",&j);
		if(campo2[i][j]==1){
			printf("Colpito\n");
			campo2[i][j]=-1;																				
			if(campo2[i-1][j]==0 && campo2[i+1][j]==0){
				for(uno=0;campo2[i][j]==-1 && uno==0;j++);            
				if(campo2[i][j]==1)
					uno=1;		
				for(uno=0;campo2[i][j]==-1 && uno==0;j--);
				if(campo2[i][j]==1)
					uno=1;	
			}
			else{
				for(uno=0;campo2[i][j]==-1 && uno==0;i++);            
				if(campo2[i][j]==1)
					uno=1;		
				for(uno=0;campo2[i][j]==-1 && uno==0;i--);
				if(campo2[i][j]==1)
					uno=1;
			}
			if(uno==0)
				printf("Affondato!\n");
		}
		else
			printf("Mancato :(\n");
		partita_finita=1;
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if(campo2[i][j]==1)
					partita_finita=0;
			}
		}
		if(partita_finita==1)
			printf("Giocatore 1 ha vinto!");
		else{
			printf("Giocatore 2 inserisci una posizione dove colpire(inserire riga e premere invio - inserire colonna e premere invio): ");
			scanf("%d",&i);
			scanf("%d",&j);
			if(campo1[i][j]==1){
				printf("Colpito\n");
				campo1[i][j]=-1;																				
				if(campo1[i-1][j]==0 && campo1[i+1][j]==0){
					for(uno=0;campo1[i][j]==-1 && uno==0;j++);            
					if(campo1[i][j]==1)
						uno=1;		
					for(uno=0;campo1[i][j]==-1 && uno==0;j--);
					if(campo1[i][j]==1)
						uno=1;	
				}
				else{
					for(uno=0;campo1[i][j]==-1 && uno==0;i++);            
					if(campo1[i][j]==1)
						uno=1;		
					for(uno=0;campo1[i][j]==-1 && uno==0;i--);
					if(campo1[i][j]==1)
						uno=1;
				}
				if(uno==0)
					printf("Affondato!\n");
			}
			else
				printf("Mancato :(\n");
			for(partita_finita=1,i=0;i<N;i++){
				for(j=0;j<N;j++){
					if(campo1[i][j]==1)
						partita_finita=0;
				}
			}
			if(partita_finita==1)
			printf("Giocatore 2 ha vinto!");
		}			
	} 
	return 0;
}

void posizionamento_navi(int lunghezza_nave){
	int i,j,k,direzione,valido=0;
	while(valido==0){
		direzione=rand()%4+1; //direzione nave  1=destra 2=sinistra 3=su 4=giu
		k=lunghezza_nave;
		i=rand()%N;
	    j=rand()%N;
		switch(direzione){
			case 1:
				if(campo1[i][j]==0){
					for(valido=1;k>=0 && valido==1;k--){
						if(j+k>=N || campo1[i][j+k]!=0 || campo1[i+1][j+k]!=0 || campo1[i-1][j+k]!=0)
							valido=0;
					}
			    }
				break;
			case 2:
				if(campo1[i][j]==0){
					for(valido=1;k>=0 && valido==1;k--){
						if(j-k<0 || campo1[i][j-k]!=0 || campo1[i+1][j-k]!=0 || campo1[i-1][j-k]!=0)
							valido=0;
					}
			    }
				break;
			case 3:
				if(campo1[i][j]==0){
					for(valido=1;k>=0 && valido==1;k--){
						if(i-k<0 || campo1[i-k][j]!=0 || campo1[i-k][j+1]!=0 || campo1[i-k][j-1]!=0)
							valido=0;
					}
			    }
				break;
			case 4:
				if(campo1[i][j]==0){
					for(valido=1;k>=0 && valido==1;k--){
						if(i+k>=N || campo1[i+k][j]!=0 || campo1[i+k][j+1]!=0 || campo1[i+k][j-1]!=0)
							valido=0;
					}
				}
				break;												
		}
	}
	switch(direzione){
		case 1:
			for(k=0;k<lunghezza_nave;k++)
				campo1[i][j+k]=1;
			break;
		case 2:
			for(k=0;k<lunghezza_nave;k++)
				campo1[i][j-k]=1;
			break;	
		case 3:
			for(k=0;k<lunghezza_nave;k++)
				campo1[i-k][j]=1;
			break;	
		case 4:
			for(k=0;k<lunghezza_nave;k++)
				campo1[i+k][j]=1;
			break;																
	}
}

void posizionamento_navi2(int lunghezza_nave){
	int i,j,k,direzione,valido=0;
	while(valido==0){
		direzione=rand()%4+1; //direzione nave  1=destra 2=sinistra 3=su 4=giu
		k=lunghezza_nave;
		i=rand()%N;
		j=rand()%N;
		switch(direzione){
			case 1:
				if(campo2[i][j]==0){
					for(valido=1;k>=0 && valido==1;k--){
						if(j+k>=N || campo2[i][j+k]!=0 || campo2[i+1][j+k]!=0 || campo2[i-1][j+k]!=0)
							valido=0;
					}
			    }
				break;
			case 2:
				if(campo2[i][j]==0){
					for(valido=1;k>=0 && valido==1;k--){
						if(j-k<0 || campo2[i][j-k]!=0 || campo2[i+1][j-k]!=0 || campo2[i-1][j-k]!=0)
							valido=0;
					}
			    }
				break;
			case 3:
				if(campo2[i][j]==0){
					for(valido=1;k>=0 && valido==1;k--){
						if(i-k<0 || campo2[i-k][j]!=0 || campo2[i-k][j+1]!=0 || campo2[i-k][j-1]!=0)
							valido=0;
					}
			    }
				break;
			case 4:
				if(campo2[i][j]==0){
					for(valido=1;k>=0 && valido==1;k--){
						if(i+k>=N || campo2[i+k][j]!=0 || campo2[i+k][j+1]!=0 || campo2[i+k][j-1]!=0)
							valido=0;
					}
				}
				break;												
		}
	}
	switch(direzione){
		case 1:
			for(k=0;k<lunghezza_nave;k++)
				campo2[i][j+k]=1;
			break;
		case 2:
			for(k=0;k<lunghezza_nave;k++)
				campo2[i][j-k]=1;
			break;	
		case 3:
			for(k=0;k<lunghezza_nave;k++)
				campo2[i-k][j]=1;
			break;	
		case 4:
			for(k=0;k<lunghezza_nave;k++)
				campo2[i+k][j]=1;
			break;																
	}
}
