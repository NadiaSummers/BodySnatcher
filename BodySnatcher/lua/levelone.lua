--levelone.lua
--generation calls for world building
--23/04/2014 Nadia Summers

--grass		0	"textures/ground.png"
--dirt		1	"textures/dirt.png"
--cobble	2	"textures/cobble.png"

texManager = TextureManager();
texManager:loadTexture(0, "textures/ground.png");
texManager:loadTexture(1, "textures/dirt.png");
texManager:loadTexture(2, "textures/cobble.png");

newTerrain = Terrain();
newTerrain:setScalingFactor(16, 2, 16);
newTerrain:generateTerrain(texManager:getTexture(0), "textures/terrainheightmap.raw", 512);
newTerrain:addMapLayer(texManager:getTexture(1), "textures/tex-dirt512.raw");
newTerrain:addMapLayer(texManager:getTexture(2), "textures/tex-cobble512.raw");