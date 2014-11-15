--some preload values
makesLotOfSense = 42
i = 0

function run()
	i = i + 1
	MsgBox("Hello world says " .. tostring(makesLotOfSense) .. " for the " .. tostring(i) .. ". time!")
end