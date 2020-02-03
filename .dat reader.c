#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define data(x) x.data_type
#define name(x) x.name
#define d1(x) x.d1
#define d2(x) x.d2
#define value(x) x.value
#define dob(x) x.value.d
#define fl(x) x.value.f
#define in(x) x.value.i
#define ch(x) x.value.c
#define lo(x) x.value.l
#define ui(x) x.value.ui
#define uc(x) x.value.uc
#define loc(x) x.byte
#include <string.h>

int compare_strings(char *p1, char *p2){
	int i = 0;
	while(p1[i]!='\0'){
		if(p1[i]!=p2[i]){
			return 0;
		}
		i++;
	}
	return 1;
	
	
	
}
int is_array_number(char *p){
	int i=0;
	char letter;
	while((letter=p[i])!='['){
		i++;
	}
	i++;
	while((letter=p[i])!=']'){
		if(!((letter=='0')||(letter=='1')||(letter=='2')||(letter=='3')||(letter=='4')||(letter=='5')||(letter=='6')||(letter=='7')||(letter=='8')||(letter=='9'))){
			
			return 0;
			
			
		}
		i++;
		
	}
	return 1;
}
int is_array_number_2(char *p){
	int i=0,j=-1;
	char letter;
	while((letter=p[i])!=']'){
		
		i++;
	}
	
	
	i++;
	letter=p[i];
	
	while((letter!=']')&&(letter!='\0')){
		
		if(letter=='['){
			i++;
			letter=p[i];
			continue;
		}
		if(!((letter=='0')||(letter=='1')||(letter=='2')||(letter=='3')||(letter=='4')||(letter=='5')||(letter=='6')||(letter=='7')||(letter=='8')||(letter=='9'))){
			
			return 0;
			
			
		}
		j=1;
		i++;
		letter=p[i];
		
		
	}
	if(j==1){
		return 1;
	}
	else{
		return -1;
	}
}




int type_of(char *t){
    if(t[0]=='i'){
        return 1;
    }
    else if(t[0]=='c'){
        return 2;
    }
    else if(t[0]=='l'){
        return 3;
    }
    else if(t[0]=='d'){
        return 4;
    }
    else if(t[0]=='f'){
        return 5;
    }
    else{
        if(t[1]=='i'){
            return 6;
        }
        else if(t[1]=='c'){
            return 7;
        }
    }
    
} 
int string_to_num(char *p, int l){
	
	if(l==0){
		return 0;
	}
	else if(*p=='0'){
			return 0*(pow(10,l-1))+string_to_num(p+1,l-1);
		}
	else if(*p=='1'){
			return 1*(pow(10,l-1))+string_to_num(p+1,l-1);
		}
	else if(*p=='2'){
			return 2*(pow(10,l-1))+string_to_num(p+1,l-1);
		}
	else if(*p=='3'){
			return 3*(pow(10,l-1))+string_to_num(p+1,l-1);
		}
	else if(*p=='4'){
			return 4*(pow(10,l-1))+string_to_num(p+1,l-1);
		}
	else if(*p=='5'){
			return 5*(pow(10,l-1))+string_to_num(p+1,l-1);
		}
	else if(*p=='6'){
			return 6*(pow(10,l-1))+string_to_num(p+1,l-1);
		}
	else if(*p=='7'){
			return 7*(pow(10,l-1))+string_to_num(p+1,l-1);
		}
	else if(*p=='8'){
			return 8*(pow(10,l-1))+string_to_num(p+1,l-1);
		}
	else if(*p=='9'){
			return 9*(pow(10,l-1))+string_to_num(p+1,l-1);
		}								
	}
char *simple_name(char *p){
	int i=1;
	char *name;
	name = (char *)malloc(sizeof(char));
	while(p[i-1]!='['){
		name = (char *)realloc(name,sizeof(char)*(i+1));
		name[i-1]=p[i-1];
		name[i]='\0';
		i++;
	}
	return name;
}	
int is_array(char *p){
	
	int b=0;
	for(;p[b]!='\0';b++){
		if(p[b]=='['){
			
			return 1;
		}
		
	
		
	}	
	return 0;
	
	
	
}	
char *name_finder_from_d1(char *p){
	char *name;
	int i=0,k=1;
	name =(char*)malloc(sizeof(char));
	while(p[i]!='['){
		i++;
	}
	i++;
	while(p[i]!=']'){
		
		name = (char*)realloc(name,sizeof(char)*(k+1));
		name[k-1] = p[i];
		name[k] = '\0';
		i++;
		k++;
	}
	return name;
	
	
	
}	
char *name_finder_from_d2(char *p){
	char *name;
	int i=0,k=1;
	name =(char*)malloc(sizeof(char));
	while(p[i]!='['){
		i++;
	}
	i++;
	while(p[i]!='['){
		i++;
	}
	i++;
	while(p[i]!=']'){
		
		name = (char*)realloc(name,sizeof(char)*(k+1));
		name[k-1] = p[i];
		name[k] = '\0';
		i++;
		k++;
	}
	return name;
	
	
	
}
int first_array(char *p){
	
	int counter,ans=-1;
	int b=0;
	for(;p[b]!='\0';b++){
		if(p[b]=='['){
			
			counter = 0;
			while(p[b]!=']'){
				counter++;
				b++;
			}
		
			
			ans = string_to_num(p+(b-counter)+1,counter-1);
			
			
			
			return ans;
			
		}
		
		}
		

		
		
	return ans;
	
	
	
}
int sec_array(char *p){
	
	int counter,ans1=-1,ans,counter2=0;
	int b=0;
	for(;p[b]!='\0';b++){
		if(p[b]=='['){
			
			counter = 0;
			while(p[b]!=']'){
				counter++;
				b++;
			}
			
		
			ans = string_to_num(p+(b-counter)+1,counter-1);
			counter2++;	
			
			
		}
		
		
		
	}
	if(counter2==2){
		return ans;
	}
	else if(counter2==1){
	
	return ans1;
}
	
	
}
int converter(int number){
	
	switch(number){
		case 1:
			return sizeof(int);
			break;
		case 2:
			return sizeof(char);
			break;
		case 3:
			return sizeof(long);
			break;
		case 4:
			return sizeof(double);
			break;
		case 5:
			return sizeof(float);
			break;
		case 6:
			return sizeof(unsigned int);
			break;		
		case 7:
			return sizeof(unsigned char);
			break;
		
	}
	
	
	
}

char *name_finder(char *ruby){
	char *name;
	int i,tip,mem;
	name = (char *)malloc(sizeof(char));
	tip = type_of(ruby);
	switch(tip){
	
	case 1:
		mem = 2;
		i = 3;
		while(ruby[i]!='\0'&&ruby[i]!='['){
		
		name = (char *)realloc(name,sizeof(char)*mem);	
		name[mem-2]= ruby[i];
		name[mem-1]= '\0';
		mem++;
		i++;
	}
		return name;
		break;
	case 2:
		mem = 2;
		i = 4;
		while(ruby[i]!='\0'&&ruby[i]!='['){
		
		name = (char *)realloc(name,sizeof(char)*mem);	
		name[mem-2]= ruby[i];
		name[mem-1]= '\0';
		mem++;
		i++;
	}
		return name;
		break;
	case 3:
		mem = 2;
		i = 4;
		while(ruby[i]!='\0'&&ruby[i]!='['){
		
		name = (char *)realloc(name,sizeof(char)*mem);	
		name[mem-2]= ruby[i];
		name[mem-1]= '\0';
		mem++;
		i++;
	}
		return name;
		break;	
	case 4:
		mem = 2;
		i = 6;
		while(ruby[i]!='\0'&&ruby[i]!='['){
		
		name = (char *)realloc(name,sizeof(char)*mem);	
		name[mem-2]= ruby[i];
		name[mem-1]= '\0';
		mem++;
		i++;
	}
		return name;
		break;	
	case 5:
		mem = 2;
		i = 5;
		while(ruby[i]!='\0'&&ruby[i]!='['){
		
		name = (char *)realloc(name,sizeof(char)*mem);	
		name[mem-2]= ruby[i];
		name[mem-1]= '\0';
		mem++;
		i++;
	}
		return name;
		break;
	case 6:
		mem = 2;
		i = 4;
		while(ruby[i]!='\0'&&ruby[i]!='['){
		
		name = (char *)realloc(name,sizeof(char)*mem);	
		name[mem-2]= ruby[i];
		name[mem-1]= '\0';
		mem++;
		i++;
	}
		return name;
		break;
	case 7:
		mem = 2;
		i = 5;
		while(ruby[i]!='\0'&&ruby[i]!='['){
		
		name = (char *)realloc(name,sizeof(char)*mem);	
		name[mem-2]= ruby[i];
		name[mem-1]= '\0';
		mem++;
		i++;
	}
		return name;
		break;
	}	
}
struct variable{
	int d1,d2;
	char *name;
	int data_type;
	long byte;
	union {
		double d;
		float f;
		int i;
		char c;
		long l;
		unsigned char uc;
		unsigned int ui;
	}value;

};
FILE *f;
typedef struct variable var;
var google(var *obj,char *name){
	int a,b;
	a = 0;
	
	while(1){
		if(compare_strings(name(obj[a]),name)){
			return obj[a];
		}
		a++;
		
	}
	
		
	
}

int main(){
	long byte=0,byte2,cvp3;
	int i=0,k=1,number_of_vars=0,word_2=0,word_1=0,fc=1,sc=1,cs=0,a1,a2,cvp1;
	var *objects;
	float cvp5;
	char a,cvp2;
	double cvp4; 
    int x;
    unsigned int cvp6;
    unsigned char cvp7;
    char *mert, **word_3,*temp_name,*file_name,*searched_name,*sn,*nam1,*nam2;
    int p=2;
    
    int q=1;
    file_name = (char*)malloc(sizeof(char));
    while((a = getchar())!='\n'){
    	if(a != ' '){
    		file_name = (char*)realloc(file_name,sizeof(char)*(fc+1));
    		file_name[fc-1] = a;
    		file_name[fc] = '\0';
    		fc++;
		}
    	
    	
	}
    f = fopen(file_name,"r");
    word_3 = (char**)malloc(sizeof(char*));
    mert = (char*)malloc(sizeof(char));
    objects = (var*)malloc(sizeof(var));
    while((a = getchar())!='\n'){
        if(a==' '){
            
            
            continue;
        }
        else if(a!=','){ 
            mert =  (char*)realloc(mert,sizeof(char)*p); 
            mert[p-1]= '\0';
            mert[p-2]= a;
            p++;
            
            continue;
        }
        else{
            
            word_3 =  (char**)realloc(word_3,sizeof(char*)*q);
            word_3[q-1] = (char*)malloc(sizeof(char)*(p-1));
            number_of_vars++;
            strcpy(word_3[q-1], mert);
            p=2;
            
            q++;

            
            
        }
        
    }
    
    word_3 =  (char**)realloc(word_3,sizeof(char*)*q);
    word_3[q-1] = (char*)malloc(sizeof(char)*(p-1));        
    strcpy(word_3[q-1], mert);
    number_of_vars++;
  
	objects = (var*)malloc(sizeof(var));
	while(i<number_of_vars){
		objects =  (var*)realloc(objects,sizeof(var)*(i+1));
		name((objects[i])) = name_finder(word_3[i]);
		data((objects[i])) = type_of(word_3[i]);
		if(!(is_array(word_3[i]))){
		d1(objects[i]) = -1;
		d2(objects[i]) = -1;
		loc((objects[i])) = byte;
		
		byte += converter(data((objects[i])));
		 	
		if((data((objects[i])))==1){
			fseek(f,loc((objects[i])),SEEK_SET);
			fread(&(in(objects[i])),converter(data((objects[i]))),1,f);	
			
			
			i++;
		}
		else if((data((objects[i])))==2){
			fseek(f,loc((objects[i])),SEEK_SET);
			fread(&(ch(objects[i])),converter(data((objects[i]))),1,f);		
			i++;
		}
		else if((data((objects[i])))==3){
			fseek(f,loc((objects[i])),SEEK_SET);
			fread(&(lo(objects[i])),converter(data((objects[i]))),1,f);	
				
			i++;
		}
		else if((data((objects[i])))==4){
			fseek(f,loc((objects[i])),SEEK_SET);
			fread(&(dob(objects[i])),converter(data((objects[i]))),1,f);		
			i++;
		}
		else if((data((objects[i])))==5){
			fseek(f,loc((objects[i])),SEEK_SET);
			fread(&(fl(objects[i])),converter(data((objects[i]))),1,f);		
			i++;
		}
		else if((data((objects[i])))==6){
			fseek(f,loc((objects[i])),SEEK_SET);
			fread(&(ui(objects[i])),converter(data((objects[i]))),1,f);		
			i++;
		}
		else if((data((objects[i])))==7){
			fseek(f,loc((objects[i])),SEEK_SET);
			fread(&(uc(objects[i])),converter(data((objects[i]))),1,f);		
			i++;
		}
		}
		else{
			loc(objects[i]) = byte;
			if((is_array_number(word_3[i]))==1){
			
			d1(objects[i]) = first_array(word_3[i]);
			d2(objects[i]) = is_array_number_2(word_3[i]);
			if((d2(objects[i]))== 1){
				d2(objects[i]) = sec_array(word_3[i]);
			}
			else if((d2(objects[i]))== 0){
				temp_name = name_finder_from_d2(word_3[i]);
				d2(objects[i]) = in(google(objects,temp_name));
				free(temp_name);
				
			}
			if(d2(objects[i]) != -1){
				
				byte = byte + (converter(data(objects[i])))*(d1(objects[i]))*(d2(objects[i]));
			}
			else{
				byte = byte + converter(data(objects[i]))*(d1(objects[i]));
			}
			i++;
		}
		else{
			temp_name = name_finder_from_d1(word_3[i]);
			d1(objects[i]) = in(google(objects,temp_name));
			
			free(temp_name);
			d2(objects[i]) = is_array_number_2(word_3[i]);
			if((d2(objects[i]))== 1){
				d2(objects[i]) = sec_array(word_3[i]);
			}
			else if((d2(objects[i]))== 0){				
				temp_name = name_finder_from_d2(word_3[i]);
				d2(objects[i]) = in(google(objects,temp_name));
				free(temp_name);
				
			}
			if(d2(objects[i]) != -1){
				byte = byte + (converter(data(objects[i])))*(d1(objects[i]))*(d2(objects[i]));
			}
			else{
				byte = byte + converter(data(objects[i]))*(d1(objects[i]));
			}
			i++;
			
			
			
			
		}
		}
		
	}
	searched_name = (char*)malloc(sizeof(char));
	cs=0;
	while((a=getchar())!=EOF){
		
		if(a!=' '){
			if(a!=','){
				searched_name = (char*)realloc(searched_name,(sc+1)*sizeof(char));
				searched_name[sc-1]=a;
				searched_name[sc]='\0';
				sc++;
			}
			else{
				
				temp_name=searched_name;
				
				if(cs==1){
								printf("\n");
							}
							cs=1;
			if(!(is_array(temp_name))){
				
				sc=1;
				word_2=0;
				word_1=0;
				
			
			while(word_2<number_of_vars){
				while((name(objects[word_2]))[word_1]!='\0'){
					if((name(objects[word_2]))[word_1]==temp_name[word_1]){
						word_1++;
						if((name(objects[word_2]))[word_1]=='\0'){
							
							if((data(objects[word_2]))== 1){
								printf("%d",in(objects[word_2]));
							}
							else if((data(objects[word_2]))== 2){
								printf("%d",ch(objects[word_2]));
							}
							else if((data(objects[word_2]))== 3){
								printf("%ld",lo(objects[word_2]));
							}
							else if((data(objects[word_2]))== 4){
								printf("%lf",dob(objects[word_2]));
							}																	/* ARRAY DEÐÝLSE */
							else if((data(objects[word_2]))== 5){
								printf("%f",fl(objects[word_2]));
							}
							else if((data(objects[word_2]))== 6){
								printf("%ud",ui(objects[word_2]));
							}
							else if((data(objects[word_2]))== 7){
								printf("%ud",uc(objects[word_2]));
							}
							break;
						}
						continue;
					}
					else{
						word_1=0;
						word_2++;
						break;
					}
				}
				if(word_1!=0){
					break;
				}
				
			}
			
			}
			else{
				sc =1 ;
		
				if(is_array_number(temp_name)==1){
		
					a1= first_array(temp_name);
			
				}
				else if(is_array_number(temp_name)==0){
			
					nam1 = name_finder_from_d1(temp_name);
					a1 = in(google(objects,nam1));
			
				}
				if(is_array_number_2(temp_name)==1){
			
					a2 = sec_array(temp_name);
			
					fseek(f,loc(google(objects,simple_name(temp_name)))+( (converter(data(google(objects,simple_name(temp_name)))))*((a1*(d2(google(objects,simple_name(temp_name)))))+a2)),SEEK_SET);
							if(data(google(objects,simple_name(temp_name)))==1){
								fread(&cvp1,sizeof(int),1,f);
								printf("%d",cvp1);
							}
							else if(data(google(objects,simple_name(temp_name)))==2){
							
								fread(&cvp2,sizeof(char),1,f);
								printf("%d",cvp2);
							}
							else if(data(google(objects,simple_name(temp_name)))==3){
								
								fread(&cvp3,sizeof(long),1,f);
								printf("%ld",cvp3);
							}
							else if(data(google(objects,simple_name(temp_name)))==4){
								
								fread(&cvp4,sizeof(double),1,f);
								printf("%lf",cvp4);
							}
							else if(data(google(objects,simple_name(temp_name)))==5){
								
								fread(&cvp5,sizeof(float),1,f);
								printf("%f",cvp5);
							}
							else if(data(google(objects,simple_name(temp_name)))==6){
							
								fread(&cvp6,sizeof(unsigned int),1,f);
								printf("%u",cvp6);
							}
							else if(data(google(objects,simple_name(temp_name)))==7){
								
								fread(&cvp7,sizeof(unsigned char),1,f);
								printf("%u",cvp7);
							}
				}
				else if(is_array_number_2(temp_name)==0){
			
					nam2 = name_finder_from_d2(temp_name);
					a2 = in(google(objects,nam2));
					fseek(f,loc(google(objects,simple_name(temp_name)))+( (converter(data(google(objects,simple_name(temp_name)))))*((a1*(d2(google(objects,simple_name(temp_name)))))+a2)),SEEK_SET);
							if(data(google(objects,simple_name(temp_name)))==1){
								
								fread(&cvp1,sizeof(int),1,f);
								printf("%d",cvp1);
							}
							else if(data(google(objects,simple_name(temp_name)))==2){
							
								fread(&cvp2,sizeof(char),1,f);
								printf("%d",cvp2);
							}
							else if(data(google(objects,simple_name(temp_name)))==3){
								
								fread(&cvp3,sizeof(long),1,f);
								printf("%ld",cvp3);
							}
							else if(data(google(objects,simple_name(temp_name)))==4){
								
								fread(&cvp4,sizeof(double),1,f);
								printf("%lf",cvp4);
							}
							else if(data(google(objects,simple_name(temp_name)))==5){
								
								fread(&cvp5,sizeof(float),1,f);
								printf("%f",cvp5);
							}
							else if(data(google(objects,simple_name(temp_name)))==6){
							
								fread(&cvp6,sizeof(unsigned int),1,f);
								printf("%ud",cvp6);
							}
							else if(data(google(objects,simple_name(temp_name)))==7){
								
								fread(&cvp7,sizeof(unsigned char),1,f);
								printf("%ud",cvp7);
							}
					
				}
				else if(is_array_number_2(temp_name)==-1){
					fseek(f,loc(google(objects,simple_name(temp_name)))+( (converter(data(google(objects,simple_name(temp_name)))))*a1),SEEK_SET);
					if(data(google(objects,simple_name(temp_name)))==1){
								
								fread(&cvp1,sizeof(int),1,f);
								printf("%d",cvp1);
							}
							else if(data(google(objects,simple_name(temp_name)))==2){
							
								fread(&cvp2,sizeof(char),1,f);
								printf("%d",cvp2);
							}
							else if(data(google(objects,simple_name(temp_name)))==3){
								
								fread(&cvp3,sizeof(long),1,f);
								printf("%ld",cvp3);
							}
							else if(data(google(objects,simple_name(temp_name)))==4){
								
								fread(&cvp4,sizeof(double),1,f);
								printf("%Lf",cvp4);
							}
							else if(data(google(objects,simple_name(temp_name)))==5){
								
								fread(&cvp5,sizeof(float),1,f);
								printf("%f",cvp5);
							}
							else if(data(google(objects,simple_name(temp_name)))==6){
							
								fread(&cvp6,sizeof(unsigned int),1,f);
								printf("%ud",cvp6);
							}
							else if(data(google(objects,simple_name(temp_name)))==7){
								
								fread(&cvp7,sizeof(unsigned char),1,f);
								printf("%ud",cvp7);
							}
				}
				
			}
			
		}
			
		}
		
		
	}
	temp_name=searched_name;
	printf("\n");
				cs=0;
				sc=1;
			if(!(is_array(temp_name))){
				
				
				word_2=0;
				word_1=0;
				
			
			while(word_2<number_of_vars){
				while((name(objects[word_2]))[word_1]!='\0'){
					if((name(objects[word_2]))[word_1]==temp_name[word_1]){
						word_1++;
						if((name(objects[word_2]))[word_1]=='\0'){
							if(cs==1){
								printf("\n");
							}
							cs=1;
							if((data(objects[word_2]))== 1){
								printf("%d",in(objects[word_2]));
							}
							else if((data(objects[word_2]))== 2){
								printf("%d",ch(objects[word_2]));
							}
							else if((data(objects[word_2]))== 3){
								printf("%ld",lo(objects[word_2]));
							}
							else if((data(objects[word_2]))== 4){
								printf("%lf",dob(objects[word_2]));
							}																	/* ARRAY DEÐÝLSE */
							else if((data(objects[word_2]))== 5){
								printf("%f",fl(objects[word_2]));
							}
							else if((data(objects[word_2]))== 6){
								printf("%ud",ui(objects[word_2]));
							}
							else if((data(objects[word_2]))== 7){
								printf("%ud",uc(objects[word_2]));
							}
							break;
						}
						continue;
					}
					else{
						word_1=0;
						word_2++;
						break;
					}
				}
				if(word_1!=0){
					break;
				}
				
			}
			
			}
			else{
				if(is_array_number(temp_name)==1){
					a1= first_array(temp_name);
				}
				else if(is_array_number(temp_name)==0){
					nam1 = name_finder_from_d1(temp_name);
					a1 = in(google(objects,nam1));
				}
				if(is_array_number_2(temp_name)==1){
					a2 = sec_array(temp_name);
					fseek(f,loc(google(objects,simple_name(temp_name)))+( (converter(data(google(objects,simple_name(temp_name)))))*((a1*(d2(google(objects,simple_name(temp_name)))))+a2)),SEEK_SET);
							if(data(google(objects,simple_name(temp_name)))==1){
								
								fread(&cvp1,sizeof(int),1,f);
								printf("%d",cvp1);
							}
							else if(data(google(objects,simple_name(temp_name)))==2){
							
								fread(&cvp2,sizeof(char),1,f);
								printf("%d",cvp2);
							}
							else if(data(google(objects,simple_name(temp_name)))==3){
								
								fread(&cvp3,sizeof(long),1,f);
								printf("%ld",cvp3);
							}
							else if(data(google(objects,simple_name(temp_name)))==4){
								
								fread(&cvp4,sizeof(double),1,f);
								printf("%lf",cvp4);
							}
							else if(data(google(objects,simple_name(temp_name)))==5){
								
								fread(&cvp5,sizeof(float),1,f);
								printf("%f",cvp5);
							}
							else if(data(google(objects,simple_name(temp_name)))==6){
							
								fread(&cvp6,sizeof(unsigned int),1,f);
								printf("%ud",cvp6);
							}
							else if(data(google(objects,simple_name(temp_name)))==7){
								
								fread(&cvp7,sizeof(unsigned char),1,f);
								printf("%ud",cvp7);
							}
				}
				else if(is_array_number_2(temp_name)==0){
					nam2 = name_finder_from_d2(temp_name);
					a2 = in(google(objects,nam2));
					fseek(f,loc(google(objects,simple_name(temp_name)))+( (converter(data(google(objects,simple_name(temp_name)))))*((a1*(d2(google(objects,simple_name(temp_name)))))+a2)),SEEK_SET);
							if(data(google(objects,simple_name(temp_name)))==1){
								
								fread(&cvp1,sizeof(int),1,f);
								printf("%d",cvp1);
							}
							else if(data(google(objects,simple_name(temp_name)))==2){
							
								fread(&cvp2,sizeof(char),1,f);
								printf("%d",cvp2);
							}
							else if(data(google(objects,simple_name(temp_name)))==3){
								
								fread(&cvp3,sizeof(long),1,f);
								printf("%ld",cvp3);
							}
							else if(data(google(objects,simple_name(temp_name)))==4){
								
								fread(&cvp4,sizeof(double),1,f);
								printf("%lf",cvp4);
							}
							else if(data(google(objects,simple_name(temp_name)))==5){
								
								fread(&cvp5,sizeof(float),1,f);
								printf("%f",cvp5);
							}
							else if(data(google(objects,simple_name(temp_name)))==6){
							
								fread(&cvp6,sizeof(unsigned int),1,f);
								printf("%ud",cvp6);
							}
							else if(data(google(objects,simple_name(temp_name)))==7){
								
								fread(&cvp7,sizeof(unsigned char),1,f);
								printf("%ud",cvp7);
							}
					
				}
				else if(is_array_number_2(temp_name)==-1){
					fseek(f,loc(google(objects,simple_name(temp_name)))+( (converter(data(google(objects,simple_name(temp_name)))))*a1),SEEK_SET);
					if(data(google(objects,simple_name(temp_name)))==1){
								
								fread(&cvp1,sizeof(int),1,f);
								printf("%d",cvp1);
							}
							else if(data(google(objects,simple_name(temp_name)))==2){
							
								fread(&cvp2,sizeof(char),1,f);
								printf("%d",cvp2);
							}
							else if(data(google(objects,simple_name(temp_name)))==3){
								
								fread(&cvp3,sizeof(long),1,f);
								printf("%ld",cvp3);
							}
							else if(data(google(objects,simple_name(temp_name)))==4){
								
								fread(&cvp4,sizeof(double),1,f);
								printf("%lf",cvp4);
							}
							else if(data(google(objects,simple_name(temp_name)))==5){
								
								fread(&cvp5,sizeof(float),1,f);
								printf("%f",cvp5);
							}
							else if(data(google(objects,simple_name(temp_name)))==6){
							
								fread(&cvp6,sizeof(unsigned int),1,f);
								printf("%ud",cvp6);
							}
							else if(data(google(objects,simple_name(temp_name)))==7){
								
								fread(&cvp7,sizeof(unsigned char),1,f);
								printf("%ud",cvp7);
							}
				}
				
			}
			
	
	
	word_2=0;
				word_1=0;
				temp_name=searched_name;
			while(word_2<number_of_vars){
				while((name(objects[word_2]))[word_1]!='\0'){
					if((name(objects[word_2]))[word_1]==temp_name[word_1]){
						word_1++;
						if((name(objects[word_2]))[word_1]=='\0'){
							if(cs==1){
								printf("\n");
							}
							cs=1;
							if((data(objects[word_2]))== 1){
								printf("%d",in(objects[word_2]));
							}
							else if((data(objects[word_2]))== 2){
								printf("%d",ch(objects[word_2]));
							}
							else if((data(objects[word_2]))== 3){
								printf("%ld",lo(objects[word_2]));
							}
							else if((data(objects[word_2]))== 4){
								printf("%lf",dob(objects[word_2]));
							}
							else if((data(objects[word_2]))== 5){
								printf("%f",fl(objects[word_2]));
							}
							else if((data(objects[word_2]))== 6){
								printf("%ud",ui(objects[word_2]));
							}
							else if((data(objects[word_2]))== 7){
								printf("%ud",uc(objects[word_2]));
							}
							break;
						}
						continue;
					}
					else{
						word_1=0;
						word_2++;
						break;
					}
				}
				if(word_1!=0){
					break;
				}
				
			}	
	free(searched_name);
									
	
	
	
	
	return 0;
}
