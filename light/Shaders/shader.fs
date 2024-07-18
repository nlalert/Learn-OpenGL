#version 330 core

struct Material {
    sampler2D   diffuse;  
    vec3        specular;
    float       shininess;
};

struct Light {
    vec3 position;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Light light;  
uniform Material material;

out vec4 FragColor;

in vec2 TexCoords;
in vec3 FragPos;  
in vec3 Normal;
  
uniform vec3 viewPos;

void main()
{
    //diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);  
    float diff = max(dot(norm, lightDir), 0.0f);

    //specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0f), material.shininess);

    vec3 ambient  = light.ambient * vec3(texture(material.diffuse, TexCoords));
    vec3 diffuse  = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));
    vec3 specular = light.specular * (spec * material.specular);  

    vec3 result = ambient + diffuse + specular; //not multiply objColor because seperate through diffent kind of lighting
    FragColor = vec4(result, 1.0f);
}
