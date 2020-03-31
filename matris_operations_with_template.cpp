//////////////////////////////////////////////////////////////////////////////////////////////////////
//Belirlenen dönem ödevi çerçevesinde büyük kısmı gerçeklenmiş (Matris ve Table işlemleri) kodlar. ///
//Matris operations with template and class
//////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
string def[]={"0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17"};
template <class Type>
class Matrix{
  public:
    Matrix(int rc=10,int cc=10,Type _value=0){
      rowCount = rc;
      colCount = cc;
      value = _value;
      items = new Type*[rowCount];
      for(int i=0;i<rowCount;i++){
        items[i] = new Type[colCount];
      }
      if(char(value)=='e'){
       for(int i=0;i<rowCount;i++){
        for(int j=0;j<colCount;j++){
          if(i==j)
           items[i][j] = 1;
          else
           items[i][j] = 0;
        }
       }
      }
      else if(char(value)=='r'){
       for(int i=0;i<rowCount;i++){
        for(int j=0;j<colCount;j++){

           items[i][j] = (rand() % 255) + 1;
        }
       }
      }
      else
       for(int i=0;i<rowCount;i++){
         for(int j=0;j<colCount;j++){
           items[i][j] = value;
         }
       }
      void print();
    }

    Matrix operator + (const Matrix& m){
      Matrix mnew;
      mnew.rowCount=this->rowCount;
      mnew.colCount=this->colCount;
      mnew.items=this->items;
      for(int i=0;i<rowCount;i++){
         for(int j=0;j<colCount;j++){
           mnew.items[i][j]=this->items[i][j] + m.items[i][j];
         }
      }
      return mnew;
    }

    Matrix operator - (const Matrix<Type>& m){
      Matrix mnew;
      mnew.rowCount=this->rowCount;
      mnew.colCount=this->colCount;
      mnew.items=this->items;
      for(int i=0;i<rowCount;i++){
         for(int j=0;j<colCount;j++){
           mnew.items[i][j]=this->items[i][j] - m.items[i][j];
         }
      }
      return mnew;
    }

    Matrix operator * (const Matrix& m){
      Matrix mnew;
      mnew.rowCount=this->rowCount;
      mnew.colCount=m.colCount;
      for(int i=0;i<rowCount;i++){
         for(int j=0;j<colCount;j++){
           mnew.items[i][j]=0;
           for(int k=0;k<colCount;k++){
           mnew.items[i][j]=mnew.items[i][j]+(this->items[i][k] * m.items[k][j]);
           }
         }
      }
      return mnew;
    }

    Matrix operator + (Type num){
      Matrix mnew;
      mnew.rowCount=this->rowCount;
      mnew.colCount=this->colCount;
      mnew.items=this->items;

      for(int i=0;i<rowCount;i++){
         for(int j=0;j<colCount;j++){
           mnew.items[i][j]=this->items[i][j] + num;
         }
      }
      return mnew;
    }

    Matrix operator - (Type num){
      Matrix mnew;
      mnew.rowCount=this->rowCount;
      mnew.colCount=this->colCount;
      mnew.items=this->items;

      for(int i=0;i<rowCount;i++){
         for(int j=0;j<colCount;j++){
           mnew.items[i][j]=this->items[i][j] - num;
         }
      }
      return mnew;
    }

    Matrix operator * (Type num){
      Matrix mnew;
      mnew.rowCount=this->rowCount;
      mnew.colCount=this->colCount;
      mnew.items=this->items;

      for(int i=0;i<rowCount;i++){
         for(int j=0;j<colCount;j++){
           mnew.items[i][j]=this->items[i][j] * num;
         }
      }
      return mnew;
    }

    Matrix operator / (Type num){
      Matrix mnew;
      mnew.rowCount=this->rowCount;
      mnew.colCount=this->colCount;
      mnew.items=this->items;

      for(int i=0;i<rowCount;i++){
         for(int j=0;j<colCount;j++){
           mnew.items[i][j]=this->items[i][j] / num;
         }
      }
      return mnew;
    }

    Matrix operator % (Type num){
      Matrix mnew;
      mnew.rowCount=this->rowCount;
      mnew.colCount=this->colCount;
      mnew.items=this->items;

      for(int i=0;i<rowCount;i++){
         for(int j=0;j<colCount;j++){
           mnew.items[i][j]=this->items[i][j] % num;
         }
      }
      return mnew;
    }

    Matrix operator ^ (Type num){
      Matrix mnew;
      mnew.rowCount=this->rowCount;
      mnew.colCount=this->colCount;
      mnew.items=this->items;

      for(int i=0;i<rowCount;i++){
         for(int j=0;j<colCount;j++){
           mnew.items[i][j]=pow(this->items[i][j] , num);
         }
      }
      return mnew;
    }

    void T(){
      int temp;
      if(rowCount==colCount){
        for(int i=0;i<rowCount;i++){
        for(int j=i;j<colCount;j++){

           temp=items[i][j];
           items[i][j]=items[j][i];
           items[j][i]=temp;

        }
       }
      }
      else{
        Type **newdata;
        newdata = new Type *[colCount];
        for(int i=0;i<colCount;i++){
        newdata[i] = new Type[rowCount];
        }
        for(int i=0;i<rowCount;i++){
         for(int j=0;j<colCount;j++){
           newdata[j][i]=items[i][j];
         }
       }
       for(int i=0;i<rowCount;i++){
        delete [] items[i];
      }
      delete [] items;
      items=newdata;
      temp=rowCount;
      rowCount=colCount;
      colCount=temp;
      
      return;
      }
    }

    void inv(){
        Matrix mb(rowCount,colCount,'e');
        double a,b;
        for(int i=0;i<rowCount;i++){
         a=items[i][i];
         for(int j=0;j<colCount;j++){
           items[i][j]=items[i][j] / a;
           mb.items[i][j]=mb.items[i][j] / a;
         }
         for(int k=0;k<rowCount;k++){
           if(k!=i){
             b=items[k][i];
             for(int j=0;j<colCount;j++){
               items[k][j]=items[k][j]-(items[i][j]*b);
               mb.items[k][j]=mb.items[k][j]-(mb.items[i][j]*b);
             }
           }
         }
       }
       this->items=mb.items;
       return ;
    
    }

    Matrix emul(const Matrix& m){
      Matrix mnew;
      mnew.rowCount=this->rowCount;
      mnew.colCount=this->colCount;
      mnew.items=this->items;
      for(int i=0;i<rowCount;i++){
         for(int j=0;j<colCount;j++){
           mnew.items[i][j]=this->items[i][j] * m.items[i][j];
         }
      }
      return mnew;
    }

    Type det(){
      Type  ratio, detl;
      if (rowCount == 2)
         detl= ((items[0][0] * items[1][1]) - (items[1][0] * items[0][1]));
      else if(rowCount==3){
        detl=((items[0][0]*items[1][1]*items[2][2])+(items[1][0]*items[2][1]*items[0][2])+(items[2][0]*items[0][1]*items[1][2]))-((items[0][2]*items[1][1]*items[2][0])+(items[1][2]*items[2][1]*items[0][0])+(items[2][2]*items[0][1]*items[1][0]));
      }
      else{
        for(int i = 0; i < rowCount; i++){
          for(int j = 0; j < colCount; j++){
              if(j>i){
			        ratio = items[j][i]/items[i][i];
              for(int k = 0; k < rowCount; k++){
                 items[j][k] -= ratio * items[i][k];
                 }
               }
              }
             }
            detl = 1;
            for(int i = 0; i < rowCount; i++)
             detl *= items[i][i];
      }
     return detl;
    }

    void resize(int rc,int cc){
      Type **newdata;
      if(rowCount==rc && colCount==cc)
        return;

      newdata = new Type *[rc];
      for(int i=0;i<rc;i++){
        newdata[i] = new Type[cc];
      }
      if(rowCount<=rc && colCount<=cc){
       for(int i=0;i<rowCount;i++){
         for(int j=0;j<colCount;j++){
           newdata[i][j]=items[i][j];
         }
       }
       for(int i=rowCount;i<rc;i++){
         for(int j=colCount;j<cc;j++){
           newdata[i][j]=0;
         }
       }
      }
      if(rowCount<=rc && colCount>=cc){
       for(int i=0;i<rowCount;i++){
         for(int j=0;j<cc;j++){
           newdata[i][j]=items[i][j];
         }
       }
       for(int i=rowCount;i<rc;i++){
         for(int j=0;j<cc;j++){
           newdata[i][j]=0;
         }
       }
      }
      if(rowCount>=rc && colCount<=cc){
       for(int i=0;i<rc;i++){
         for(int j=0;j<colCount;j++){
           newdata[i][j]=items[i][j];
         }
       }
       for(int i=0;i<rc;i++){
         for(int j=colCount;j<cc;j++){
           newdata[i][j]=0;
         }
       }
      }
      if(rowCount>=rc && colCount>=cc){
       for(int i=0;i<rc;i++){
         for(int j=0;j<cc;j++){
           newdata[i][j]=items[i][j];
         }
       }
      }
      for(int i=0;i<rowCount;i++){
        delete [] items[i];
      }
      delete [] items;
      items=newdata;
      rowCount=rc;
      colCount=cc;
      return;
    }

    void print(string filename){
      ofstream file;
      file.open(filename);
      for(int i=0;i<rowCount;i++){
        for(int j=0;j<colCount;j++){
          file<<setw(5)<<items[i][j];
        }
        file<<endl;
      }
        cout<<"Writing to file..."<<endl;
    }

    virtual void print(){
      for(int i=0;i<rowCount;i++){
        for(int j=0;j<colCount;j++){
          cout<<setw(5)<<items[i][j]<<"  ";
        }
        cout<<endl;
      }

    }

  protected:
  int value;
  int rowCount;
  int colCount;
  Type **items;
};

class Table:public Matrix<int>{
  public:
  Table(int rc=10,int cc=10,int _value=0):Matrix(rc,cc,_value){

    rowName = new string[rowCount];
    colName = new string[colCount];
    int s=48,k=65;
    for(int i=0;i<rowCount;i++){
        rowName[i]=def[i];

    }
    for(int i=0;i<colCount;i++){
      colName[i]=char(k);k++;
      if(k==91){
        k=65;
        colName[i]=char(k)+char(k);
      }
    }

  }

  void print(){
    int n=rowName[0].length();
    for(int i=0;i<rowCount;i++)
      cout<<" "<<setw(5)<<colName[i]<<" ";
    cout<<endl;
    for(int i=0;i<rowCount;i++){
      cout<<rowName[i];
    for(int j=0;j<colCount;j++){

      cout<<setw(5)<<items[i][j]<<"  ";
      }cout<<endl;
    }

  }

  int itemAt(int r,int c){
    return items[r][c];
  }

  int itemAt(string s){
    int n=s.length();
    int x,y;
    string a;
    string b;
    a=s[0];
    b=s.substr(1,n);
    for(int i=0;i<rowCount;i++){
      if(b==rowName[i]||a==rowName[i]){
        x=i;
      }
    }
    for(int j=0;j<colCount;j++){
      if(a==colName[j]||b==colName[j]){
        y=j;
      }

    }
    return items[x][y];

  }

  int itemAt(string rs,string cs){
    int x,y;
    for(int i=0;i<rowCount;i++){
      if(rs==this->rowName[i]||cs==this->rowName[i]){
        x=i;
      }
    }
    for(int j=0;j<colCount;j++){
      if(cs==this->colName[j]||rs==this->colName[j]){
        y=j;
      }

    }
    return items[x][y];
  }

  void setRowNames(string s[],int n){
    for(int i=0;i<n;i++){
      if(s[i].length()>9){
        cout<<"Fazla satir karakteri."<<endl;
        break;
      }
      else
       this->rowName[i]=s[i];
    }
  }
  void setColNames(string s[],int n){
    for(int i=0;i<n;i++){
      if(s[i].length()>5){
        cout<<"Fazla sutun karakteri."<<endl;
        break;
      }
      else
       this->colName[i]=s[i];
    }
  }
  private:
  string *rowName;
  string *colName;
};
int main() {
	Matrix<int> *m1 = new Matrix<int>();  //10x10 matrix with zeros.
	Matrix<int> *m2 = new Matrix<int>(3, 2, 1);  //3x2 matrix with ones
	Matrix<int> *m2 = new Matrix<int>(3, 4, 9);  // 3x4 matrix with 9’s.
	Matrix<int> *m3 = new Matrix<int>(5, 5, 'e');  //5x5 identification matrix
	Matrix<int> *m4 = new Matrix<int>(15, 15, 'r');//15x15 matrix with random integers between [0-255]
	m2->resize(5, 5); //matrix resize operations after creation
	m3->print(); // print matrix on the screen
	m3->print(“file.txt”); // write to file
	//matrix - matrix operations
	/*(*m1) = (*m1) + (*m2);
	m1 = m1 + 12;
	m1 = m1 - 20;
	m1 = m1 * 10;
	m1 = m1 / 10;
	m1 = m1 % 10;
	m1 = m1 ^ 2;*/
	m1->T(); // transpoze
	m1->emul(m2); // elementwise multiply
	m1->inv(); // matrix inversion if available
	m1->det(); // determinant of matrix

}
