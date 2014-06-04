%w[sinatra haml].each{|gem| require gem}





get '/' do 
 haml :index
end

post '/' do
 search = []
 input = [] 
 search = params[:search]
 input = params[:test]

 a = 0
 b = 1
 output = []
 input.split(" ").each do |me|

 if me.match(/#{search}/) 

  output[a] = me.gsub("#{search}", "#{search}(#{b.to_s})")
  b += 1

 else
  output[a] = me
 end
 a += 1

 end

 output = output.join(" ")
 @answer = output
end

