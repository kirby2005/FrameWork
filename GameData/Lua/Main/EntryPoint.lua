local GameMain = require "Main.GameMain"

_G.EntryPoint = function()
    print("Lua EntryPoint")

    local gameMain = GameMain.Instance()
    gameMain:GameInit()
end

_G.Tick = function(deltaTime)
    -- print("Lua Tick", deltaTime)
end