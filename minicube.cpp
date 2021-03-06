#include <minicube.h>

// Constructor
Minicube::Minicube (Object *parent) : Cube()
{
	// Se usa proyeccion ortogonal
	ortho = true;

	// Posicion, escala y rotacion
	offset  = glm::vec2((GLfloat) Object::win_h * 0.080F);
	scale_1 = glm::vec3((GLfloat) Object::win_h * 0.075F);
	rot_ref = parent->rotPointer();

	// Crea cada calcomania con las texturas
	for (GLubyte i = 0; i < 6; i++)
	{
		const Sticker::FACE dir = (Sticker::FACE) i;

		sticker_texture[dir] = new Texture(path + "/minicube_" + std::string(1, i + '0') + ".png");

		sticker[dir]->side = dir;
		sticker[dir]->diffuse = glm::vec4(1.0F);
		sticker[dir]->texture_sd = sticker_texture[i];
	}

	// Debe dibujarse
	drawable = true;
}

// Asigna la informacion de la pantalla
void Minicube::updatePosition ()
{
	// Actualiza valores
	offset  = glm::vec2((GLfloat) Object::win_h * 0.080F);
	scale_1 = glm::vec3((GLfloat) Object::win_h * 0.075F);

	// Reubicacion
	pos_1.x = (GLfloat) win_w - offset.x;
	pos_1.y = offset.y;
}

void Minicube::draw() const
{
	// Respaldo la matriz actual
	glPushMatrix();
	glLoadIdentity();

	// Transformaciones
	glTranslatef(pos_1.x, pos_1.y, pos_1.z);
	glMultMatrixf(glm::value_ptr(glm::mat4_cast(*rot_ref)));
	glScalef(scale_1.x, scale_1.y, scale_1.z);

	// Dibujar caras
	for (GLubyte i = 0; i < 6; i++)
	{
		sticker[i]->draw();
	}

	// Carga material y dibujar objeto
	loadMaterial();
	Cube::cube_sd->draw();

	// Regresa a la matriz anterior
	glPopMatrix();
}

// Destructor
Minicube::~Minicube()
{
	for (GLubyte i = 0; i < 6; i++)
	{
		delete sticker_texture[i];
	}
}

