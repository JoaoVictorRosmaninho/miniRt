

class Triangulo
    def initialize(a, b, c)
        @t1 = a
        @t2 = b
        @t3 = c
    end

    def calcular_vetor_normal_triangulo
        # encontrar a linha normal do plano
        # para isso precisamos de dois vetores que se cruzam
        # Em um triangulo podemos escolher dois dos 3 lados

        # a = t2 - t1
        a = @t1.map.with_index { |item, index| @t2[index] - item }
        # b = t3 - t1 
        b = @t1.map.with_index { |item, index| @t3[index] - item }

        # com  as duas linhas podemos calcular o produto dos vetores

        # multiplicação de vetor
        result = [
            a[1] * b[2]  - a[2] * b[1],
            a[2] * b[0]  - a[0] * b[2],
            a[0] * b[2]  - a[1] * b[0]
        ]
        return result ;
    end

end



# Trinagulo 
# Um Tringulo terá três coordenadas, um para cada lado


triangulo = Triangulo.new(
    [5,8,10],
    [6,9,11],
    [4,5,7]
)

puts "resultado: #{triangulo.calcular_vetor_normal_triangulo}"