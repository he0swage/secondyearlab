const textElement = document.querySelector(".scramble");
const chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

textElement.addEventListener("mouseover", () => {
    let iterations = 0;
    const originalText = textElement.dataset.text;

    const interval = setInterval(() => {
        textElement.textContent = originalText
            .split("")
            .map((letter, index) => {
                if (index < iterations) {
                    return originalText[index];
                }
                return chars[Math.floor(Math.random() * chars.length)];
            })
            .join("");

        iterations += 1 / 3;

        if (iterations >= originalText.length) {
            clearInterval(interval);
            textElement.textContent = originalText; // assure le texte final
        }
    }, 30);
});
