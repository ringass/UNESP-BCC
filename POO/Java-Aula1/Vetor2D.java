public class Vetor2D {
    float x, y;

    Vetor2D(float x, float y){
        this.x = x;
        this.y = y;
    }

    public float prodEscalar(float x,  float y){
        float ans;

        ans = (this.x * x) + (this.y * y); 

        return ans;
    }

    public static void main(String[] args){
        Vetor2D v = new Vetor2D(7, 2);

        System.out.format("produto escalar: %.1f", v.prodEscalar(1,2));
    }
}
