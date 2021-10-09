#include <iostream>
#include <string>
using namespace std;

enum class Material {Wood,Board,Steel,foam};
class Furniture
{
protected:
    double price;
    double discount;
    Material madeof;
    string Product_Name;

public:
    Furniture()
    {

    }
    void setPrice(double val)
    {
        if(val>0)
            price=val;
    }
    void setDiscount(double val)
    {
        if(val<=price)
            discount=val;
    }
    void setDiscountPercentage(double dp)
    {
        double netDiscoount = getPrice()*(dp/100);
        setDiscount(netDiscoount);
    }
    double getPrice()
    {
        return price;
    }
    double getDiscountPrice()
    {
        return (price-discount);
    }
    void setMadeof(Material val)
    {
        madeof=val;
    }
    string getMadeof()
    {
        if(madeof==Material::Wood)
            return string("Wood");
        else if(madeof==Material::Board)
            return string("Board");
        else if(madeof==Material::Steel)
            return string("Steel");
        else
            return string("");
    }
    void setProductName(string Name)
    {
        Product_Name = Name;
    }
    string getProductName()
    {
        return Product_Name;
    }
    virtual void productDetails()=0;
};



enum class BedSize {Single,SemiDouble,Double};

class Bed:public Furniture
{
protected:
    BedSize BS;

public:
    Bed(double price,double discPr,Material mat,BedSize bs)
    {
        Furniture::setPrice(price);
        Furniture::setDiscount(discPr);
        Furniture::setMadeof(mat);
        setBedSize(bs);
    }
    void setBedSize(BedSize Bsize)
    {
        BS = Bsize;
    }
    string getBedSize()
    {
        if(BS==BedSize::Double)
            return string("Double");
        else if(BS==BedSize::SemiDouble)
            return string("SemiDouble");
        else if(BS==BedSize::Single)
            return string("Single");
        else
            return string(" ");
    }

    void productDetails()
    {
        cout<<"----------------------------"<<endl;
        cout<<"Regular Price: "<<getPrice()<<endl;
        cout<<"Discounted Price: "<<getDiscountPrice()<<endl;
        cout<<"Material: "<<getMadeof()<<endl;
        cout<<"Bed Size: "<<getBedSize()<<endl;
        cout<<"Product Name: "<<getProductName()<<endl;
        cout<<"############################"<<endl;
        cout<<" "<<endl;

    }
};

enum class SofaSize {One,Two,Three,Four,Five};
class Sofa:public Furniture
{
protected:
    SofaSize SS;

public:
    Sofa(double price,double discPr,Material m,SofaSize ss)
    {
        Furniture::setPrice(price);
        Furniture::setDiscount(discPr);
        Furniture::setMadeof(m);
        setSeatNo(ss);
    }
    void setSeatNo(SofaSize S_size)
    {
        SS = S_size;
    }
    string getSeatNo()
    {
        if(SS==SofaSize::One)
            return string("One");
        else if(SS==SofaSize::Two)
            return string("Two");
        else if(SS==SofaSize::Three)
            return string("Three");
        else if(SS==SofaSize::Four)
            return string("Four");
        else if(SS==SofaSize::Five)
            return string("Five");

        else
            return string("");

    }

    void productDetails()
    {
        cout<<"----------------------------"<<endl;
        cout<<"Regular Price: "<<getPrice()<<endl;
        cout<<"Discounted Price: "<<getDiscountPrice()<<endl;
        cout<<"Material: "<<getMadeof()<<endl;
        cout<<"Seat Number: "<<getSeatNo()<<endl;
        cout<<"Product Name: "<<getProductName()<<endl;
        cout<<"############################"<<endl;
        cout<<" "<<endl;
    }
};
enum class AlmirahSize {Two,Three,Four};
class Almirah:public Furniture
{
protected:
    AlmirahSize AS;
    string ProdName;
public:
    Almirah(double p,double dp,Material m,AlmirahSize as)
    {
        Furniture::setPrice(p);
        Furniture::setDiscount(dp);
        Furniture::setMadeof(m);
        setSize(as);
    }
    void setSize(AlmirahSize Asize)
    {
        AS = Asize;
    }
    string getSize()
    {
        if(AS==AlmirahSize::Two)
            return string("Two");
        else if(AS==AlmirahSize::Three)
            return string("Three");
        else if(AS==AlmirahSize::Four)
            return string("Four");

        else
            return string(" ");

    }


    void productDetails()
    {
        cout<<"----------------------------"<<endl;
        cout<<"Regular Price: "<<getPrice()<<endl;
        cout<<"Discounted Price: "<<getDiscountPrice()<<endl;
        cout<<"Material: "<<getMadeof()<<endl;
        cout<<"Size: "<<getSize()<<endl;
        cout<<"Product Name: "<<getProductName()<<endl;
        cout<<"############################"<<endl;
        cout<<" "<<endl;

    }
};

/**task 4
**/
void sort_order(Furniture **f1,Furniture **f2)
{
    if ((*f1)->getDiscountPrice() < (*f2)->getDiscountPrice())
    {
        Furniture* temp = *f1;
        *f1 = *f2;
        *f2 = temp;
    }
}
void sort_furniture_discount(Furniture **f,int no_of_furnitures)
{
    for (int i=0; i<no_of_furnitures-1; ++i)
    {
        for (int j=i+1; j<no_of_furnitures; ++j)
        {
            sort_order(f+i, f+j);
        }
    }
}


int main()
{
    Furniture* f_list[100];

    /**
        task 1
    */
    f_list[0] = new Bed(10000,123,Material::Wood,BedSize::Single);
    f_list[1] = new Sofa(11000,234,Material::Steel,SofaSize::Five);
    f_list[2] = new Almirah(13000,345,Material::Wood,AlmirahSize::Two);
    f_list[3] = new Bed(10090,123,Material::Wood,BedSize::Single);

    /**task 1 ends here*/

    /**
        task 2

        task 3 (Modify productDetails)
    */
    f_list[0]->setProductName("KBed");
    f_list[1]->setProductName("RSofa");
    f_list[2]->setProductName("NAlmirah");
    f_list[3]->setProductName("YBed");

    f_list[2]->setDiscountPercentage(30);
    for(int i=0; i<4; i++)
    {
        f_list[i]->productDetails();
        cout<<endl;
    }

    /**task 2 ends here*/
    /**task 3 ends here*/

    /**task 4
    */
    sort_furniture_discount(f_list,4);
    for(int i=0; i<4; i++)
    {
        f_list[i]->productDetails();
    }
    /**task 4 ends here*/

}
