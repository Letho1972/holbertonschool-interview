#!/usr/bin/node

const request = require('request');

// Vérifier si l'utilisateur a fourni un ID de film
if (process.argv.length !== 3) {
    console.error('Usage: node script.js <Movie ID>');
    process.exit(1);
}

// Récupérer l'ID du film à partir des arguments de la ligne de commande
const movieId = process.argv[2];

// Construire l'URL de l'API pour obtenir les informations du film
const url = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

// Faire une requête GET à l'API pour récupérer les informations du film
request(url, { json: true }, (error, response, body) => {
    if (error) {
        console.error('Erreur lors de la requête:', error);
        return;
    }

    if (response.statusCode !== 200) {
        console.error('Impossible de récupérer les informations du film:', response.statusCode);
        return;
    }

    // Extraire la liste des personnages
    const characters = body.characters;

    // Faire une requête GET pour chaque personnage
    characters.forEach(characterUrl => {
        request(characterUrl, { json: true }, (error, response, body) => {
            if (error) {
                console.error('Erreur lors de la requête:', error);
                return;
            }

            if (response.statusCode !== 200) {
                console.error('Impossible de récupérer les informations du personnage:', response.statusCode);
                return;
            }

            // Afficher le nom du personnage
            console.log(body.name);
        });
    });
});
