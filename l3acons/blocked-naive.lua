local BSIZE = 2^13		-- 8k
local f,k = assert(io.input(arg[1]), "rb"), arg[2] 
local out, total, prev_pos = '', 0, 1
while true do
  local block, rest = f:read(BSIZE, "*all")
  if not block then break end
  if rest then block = " "..block..rest ..'\n' end
  while true do
	local i,j = string.find(block, k, prev_pos + string.len(k)  )
	if i == nil then 
	  out = out..string.sub(block, prev_pos + 1, -1) 
	  break 
	end
	total = total + 1
	out = out..string.sub(block, prev_pos + 1, j).."("..total..")"; 
	prev_pos = j
  end 
end
io.close(f)
assert(io.open(arg[1], 'w')):write(out)
