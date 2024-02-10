


width  = 256
height = 256


# renderizando

File.open("image.ppm", "w") do |file|
    file.write "P3\n#{width} #{height}\n255\n"
    for h in 1..height do 
        puts "progress #{h} of #{height}"
        for w in 1..width do
            r = w.to_f  / (width - 1)
            g = h.to_f  / (height - 1)
            b = 0
    
            ir = (255 * r).to_i
            ig = (255 * g).to_i
            ib = (255 * b).to_i
            
            file.write "#{ir} #{ig} #{ib}\n"
        end
    end
end