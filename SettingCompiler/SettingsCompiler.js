const fs = require('fs');
const path = require('path');

const mapLineRegex = /\/\/%%/gi;
const keyRegex = /%key%/gi;
const valueRegex = /%value%/gi;
const mapTemplate = '\tm_map.insert(std::pair<std::string, std::string>("%key%", "%value%"));'

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
    fs.writeFile(path.resolve(__dirname, '..', 'GlobalSettings.cpp'), finishedFile, (err) => {
        if (err) throw err;
        console.log("Compiled!");
    });
}

const compile = async () => {
    const env = process.argv[2];
    const baseSettings = await readConfigFile('settings.global.json');
    const envSettings = await readConfigFile(`settings.${env}.json`);

    const settings = {
        ...baseSettings,
        ...envSettings
    };

    writeSettings(settings);
}

compile();
