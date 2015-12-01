struct Double3  
{  
    double x = 0;  
    double y = 0;  
    double z = 0;  
public:  
    Double3();  
    Double3(double a, double b, double c);  
};  
Double3 add(Double3 A, Double3 B);  
Double3 subtra(Double3 A, Double3 B);  
Double3 cross(Double3 A, Double3 B);  
double dot(Double3 A, Double3 B);  
Double3::Double3()  
{}  
Double3::Double3(double a, double b, double c)  
{  
    x = a;  
    y = b;  
    z = c;  
}  
Double3 add(Double3 A, Double3 B)  
{  
    Double3 temp;  
    temp.x = A.x + B.x;  
    temp.y = A.y + B.y;  
    temp.z = A.z + B.z;  
    return temp;  
}  
Double3 subtra(Double3 A, Double3 B)  
{  
    Double3 temp;  
    temp.x = A.x - B.x;  
    temp.y = A.y - B.y;  
    temp.z = A.z - B.z;  
    return temp;  
}  
Double3 cross(Double3 A, Double3 B)  
{  
    Double3 temp;  
    temp.x = A.y*B.z - A.z*B.y;  
    temp.y = A.z*B.x - A.x*B.z;  
    temp.z = A.x*B.y - A.y*B.x;  
    return temp;  
}  
double dot(Double3 A, Double3 B)  
{  
    return A.x*B.x + A.y*B.y + A.z*B.z;  
}  
bool inTri(Double3 A, Double3 B, Double3 C, Double3 P)  
{  
    Double3 AB = subtra(B, A);  
    Double3 AC = subtra(C, A);  
    Double3 AP = subtra(P, A);  
  
    double norm = dot(AB, AB)*dot(AC, AC) - dot(AB, AC)*dot(AB, AC);  
    double a = (dot(AP, AB)*dot(AC, AC) - dot(AP, AC)*dot(AC, AB)) / norm;  
    double b = (dot(AP, AC)*dot(AB, AB) - dot(AP, AB)*dot(AC, AB)) / norm;  
  
    return (a > 0 && b > 0 && a + b < 1);  
}  
int main()  
{  
    Double3 A = { 0, 0, 0 };  
    Double3 B = { 1, 0, 0 };  
    Double3 C = { 0, 1, 0 };  
    Double3 P = { 0.25, 0.25, 0 };  
    std::cout << inTri(A, B, C, P)<<std::endl;  
    char wait;  
    std::cin >> wait;  
    return 1;  72.	}  
