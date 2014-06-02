
#
#
# Even a trash can gets a steak every once and awhile. 
#
# - Josh Cano 
#   D31337
#

system'clear'


print "Make sure your input file is in the same directory as this executible and is named test.txt \nPlease enter your key via keyboard or telekinesis. \n\n"

search = gets
search = search.delete("\n")


input = File.read("test.txt")
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
File.open("out.txt", "a") do |me|
 me << output
end

print "\nIf everything went right you should have an out.txt file with the answer.\n\n"
