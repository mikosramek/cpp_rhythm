const fs = require('fs');
const path = require('path');

const xRegex = /%x%/gi;
const yRegex = /%y%/gi;
const mapTemplate = '\tm_notes.push_back(NoteData(sf::Vector2f(%x%, %y%)));'

const fileNameRegex = /NoteSequenceTemplate/gi;

const readConfigFile = (filename) => {
    return new Promise((res, rej) => {
        fs.readFile(path.resolve(__dirname, filename), (err, data) => {
            if (err) return rej(error);
            res(JSON.parse(data));
        })
    })
}


const writeSettings = (data) => {
    const template = fs.readFileSync(path.resolve(__dirname, 'GlobalSettingsTemplate.cpp'), 'utf8');

    const newLines = Object.entries(data).map(([key, value]) => {
        let newLine = mapTemplate;
        return newLine.replace(keyRegex, key).replace(valueRegex, value);
    })

    const finishedFile = template.replace(mapLineRegex, newLines.join('\n'));
    fs.writeFile(path.resolve(__dirname, '..', '..', 'GlobalSettings.cpp'), finishedFile, (err) => {
        if (err) throw err;
        console.log("Compiled!");
    });
}


const compile = async () => {
    const sequenceFolderPath = path.resolve(__dirname, 'Sequences')
    const sequenceFiles = fs.readdirSync(sequenceFolderPath);

    sequenceFiles.filter(value => /\.json$/.test(value))

    const sequences = [];

    for (let i = 0; i < sequenceFiles.length; i++) {
        const fileName = sequenceFiles[i];
        if (/\.json$/.test(fileName)) {
            const sequence = JSON.parse(fs.readFileSync(path.resolve(sequenceFolderPath, fileName)));
            sequences.push(sequence);
        }
    }

    console.log(sequences);
    createSequences(sequences);
}

const createSequences = (sequences) => {
    const template = fs.readFileSync(path.resolve(__dirname, 'NoteSequenceTemplate.cpp'), 'utf8');
    const templateHeader = fs.readFileSync(path.resolve(__dirname, 'NoteSequenceTemplate.h'), 'utf8');

    for (let i = 0; i < sequences; i += 1) {
        const { meta, tempo, notes } = sequences;
        const { name } = meta;
        if (!name) throw new Error(`Sequence is missing meta name (sequence index: ${i})`);
        className = name[0].toUpperCase() + name.substr(1) + 'NoteSequence';
        const header = templateHeader.replace(fileNameRegex, className);
        fs.writeFileSync(path.resolve(__dirname, className), header, 'utf8');
    }
}

compile();
