
#include "../headers/reader.h"


Node* Reader::readFromFile(char* fileName){
	Group root;
	if(ac.load(fileName)){
		vr::AC3DLoader::MaterialArray mats = ac.getMaterials();
		vr::AC3DLoader::GeometryArray geos = ac.getGeometries();
		
		size_t geoC = ac.getNumGeometries();
		
		for(size_t j=0;j<geoC;j++){
			
			Geometry geo;
			
			vr::AC3DLoader::Geometry g = geos[j];
			
			size_t verC = g.getNumVertices();
			
			vr::Vec3 trans = g.getTranslation();
			
			geo.setTexture(g.getTexture());
			geo.setTranslation(g.getTranslation());
			
			for(size_t i=0;i<verC;i++){
				
				vr::Vec3 v = g.getVertex(i);
				
				vr::AC3DLoader::Material m = mats[g.getMaterial(i)];
				
				Material mat;
				
				mat.setValues(m);
				
				vr::Vec3 nrm = g.getNormal(j);

				geo.addVertex(v);
				geo.addNormal(nrm);
				geo.addMaterial(mat);
				geo.addTextureCoords(g.getTexCoord(i));
				
				//cout<<v.x()<<(char)9<<v.y()<<(char)9<<v.z()<<(char)9<<endl;
			}
			root.addChildNode(&geo);
			
		}
	}else{
		return NULL;
	}
}
